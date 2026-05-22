/*
 * Prompt Variation Helpers
 * Different cores can be assigned different prompt styles.
 */

const char* get_prompt_for_core(int core_id) {
    switch (core_id % 4) {
        case 0: return "Think creatively and divergently about:";
        case 1: return "Consider technical constraints and feasibility for:";
        case 2: return "Find novel connections or analogies for:";
        case 3: return "Identify potential risks or failure modes of:";
        default: return "Explore:";
    }
}