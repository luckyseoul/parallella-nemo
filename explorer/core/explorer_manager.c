/*
 * Explorer Manager
 * Assigns different behavioral roles to Epiphany cores.
 */

#include "templates.h"

const char* get_template_for_core(int core_id) {
    int role = core_id % 4;
    switch (role) {
        case 0: return TEMPLATE_CREATIVE;
        case 1: return TEMPLATE_TECHNICAL;
        case 2: return TEMPLATE_RISKS;
        case 3: return TEMPLATE_CONNECTIONS;
        default: return "Explore:";
    }
}