/*
 * Parallel Explorer Core - v0.3
 * Writes usage data that epiphany-mon can display.
 */

#include <stdio.h>
#include "e_lib.h"
#include "shared_mem.h"

volatile explorer_output_t *output = (volatile explorer_output_t *)EXPLORER_OUTPUT_BASE;

int main(void) {
    int core = e_get_coreid();
    output[core].core_id = core;
    output[core].count = 8;

    for (int i = 0; i < 8; i++) {
        output[core].scores[i] = 0.4f + ((float)(core % 5) * 0.08f);
    }

    return 0;
}