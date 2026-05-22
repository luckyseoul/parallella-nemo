/*
 * etop - Lightweight Epiphany mesh monitor
 * Supports E16 (16 cores) and E64 (64 cores)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ncurses.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/sysinfo.h>

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
int color_enabled = 0;

void draw_bar(int usage) {
    int filled = (usage * BAR_WIDTH) / 100;

    if (color_enabled) {
        if (usage > 70)      attron(COLOR_PAIR(1));
        else if (usage > 40) attron(COLOR_PAIR(2));
        else                 attron(COLOR_PAIR(3));
    }

    addch('[');
    for (int i = 0; i < BAR_WIDTH; i++) {
        if (i < filled)
            addch(ACS_CKBOARD);
        else
            addch(' ');
    }
    addch(']');

    if (color_enabled) attroff(COLOR_PAIR(1) | COLOR_PAIR(2) | COLOR_PAIR(3));

    printw(" %3d%%", usage);
}

void draw_arm_stats() {
    struct sysinfo info;
    sysinfo(&info);

    double load = (info.loads[0] / 65536.0);
    long total_mem = info.totalram * info.mem_unit;
    long free_mem = info.freeram * info.mem_unit;
    int mem_percent = (int)(((total_mem - free_mem) * 100) / total_mem);

    printw("\nARM Load: %.2f   Memory: %d%% used\n", load, mem_percent);
}

void draw_mesh(explorer_output_t *outputs) {
    clear();
    attron(A_BOLD);
    printw("Epiphany Mesh Utilization (%d cores)\n\n", num_cores);
    attroff(A_BOLD);

    int cols = 4;
    if (num_cores > 32) cols = 8;

    int rows = (num_cores + cols - 1) / cols;

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            int idx = row * cols + col;
            if (idx >= num_cores) break;

            int usage = 0;
            if (outputs && outputs[idx].count > 0) {
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

    draw_arm_stats();
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
    int fd = open("/dev/mem", O_RDWR | O_SYNC);
    if (fd >= 0) {
        shared = mmap(NULL, SHARED_MEM_SIZE, PROT_READ | PROT_WRITE,
                      MAP_SHARED, fd, SHARED_MEM_BASE);
        if (shared == MAP_FAILED) shared = NULL;
    }

    initscr();
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);
    curs_set(0);

    if (has_colors()) {
        start_color();
        init_pair(1, COLOR_RED, COLOR_BLACK);
        init_pair(2, COLOR_YELLOW, COLOR_BLACK);
        init_pair(3, COLOR_GREEN, COLOR_BLACK);
        color_enabled = 1;
    }

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