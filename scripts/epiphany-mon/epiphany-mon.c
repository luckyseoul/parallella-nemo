/*
 * epiphany-mon - Lightweight Epiphany mesh monitor
 * Supports E16 (16 cores) and E64 (64 cores)
 *
 * Reads from shared memory regions defined by the Parallel Idea Engine
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ncurses.h>
#include <fcntl.h>
#include <sys/mman.h>

#define MAX_CORES 64
#define BAR_WIDTH 10
#define SHARED_MEM_BASE 0x8f000000
#define SHARED_MEM_SIZE 0x10000

typedef struct {
    uint32_t core_id;
    uint32_t count;
    char     results[16][128];
    float    scores[16];
} explorer_output_t;

int num_cores = 16;

void draw_bar(int usage) {
    int filled = (usage * BAR_WIDTH) / 100;
    addch('[');
    for (int i = 0; i < BAR_WIDTH; i++) {
        if (i < filled)
            addch(ACS_CKBOARD);
        else
            addch(' ');
    }
    addch(']');
    printw(" %3d%%", usage);
}

void draw_mesh(explorer_output_t *outputs) {
    clear();
    attron(A_BOLD);
    printw("Epiphany Mesh Utilization (%d cores)\n\n", num_cores);
    attroff(A_BOLD);

    int cols = 4;
    int rows = (num_cores + cols - 1) / cols;

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            int idx = row * cols + col;
            if (idx >= num_cores) break;

            int usage = 0;
            if (outputs && outputs[idx].count > 0) {
                // Use average score as usage proxy for now
                float avg = 0;
                for (int i = 0; i < outputs[idx].count; i++)
                    avg += outputs[idx].scores[i];
                usage = (int)((avg / outputs[idx].count) * 100);
            }

            printw("Core %2d ", idx);
            draw_bar(usage);
            printw("   ");
        }
        printw("\n");
    }

    printw("\nPress 'q' to quit\n");
    refresh();
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        num_cores = atoi(argv[1]);
        if (num_cores < 1 || num_cores > MAX_CORES)
            num_cores = 16;
    }

    explorer_output_t *shared = NULL;

    // Try to map shared memory (will fail gracefully if not available)
    int fd = open("/dev/mem", O_RDWR | O_SYNC);
    if (fd >= 0) {
        shared = mmap(NULL, SHARED_MEM_SIZE, PROT_READ | PROT_WRITE,
                      MAP_SHARED, fd, SHARED_MEM_BASE);
        if (shared == MAP_FAILED) {
            shared = NULL;
        }
    }

    initscr();
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);
    curs_set(0);

    int ch;
    while (1) {
        draw_mesh(shared);

        ch = getch();
        if (ch == 'q' || ch == 'Q')
            break;

        sleep(1);
    }

    if (shared) munmap(shared, SHARED_MEM_SIZE);
    if (fd >= 0) close(fd);

    endwin();
    return 0;
}