/*
 * Parallel Explorer Core - v0.4
 * Generates varied output based on core role.
 */

#include <stdio.h>
#include <string.h>
#include "e_lib.h"
#include "shared_mem.h"

volatile explorer_output_t *output = (volatile explorer_output_t *)EXPLORER_OUTPUT_BASE;

const char* get_role_prefix(int core) {
    switch (core % 4) {
        case 0: return "Creative idea: ";
        case 1: return "Technical note: ";
        case 2: return "Risk: ";
        case 3: return "Connection: ";
        default: return "Idea: ";
    }
}

int main(void) {
    int core = e_get_coreid();
    output[core].core_id = core;
    output[core].count = 6;

    for (int i = 0; i < 6; i++) {
        snprintf((char *)output[core].results[i], 128,
                 "%s variation %d from core %d",
                 get_role_prefix(core), i, core);
        output[core].scores[i] = 0.55f + ((float)(core % 6) * 0.07f);
    }

    return 0;
}