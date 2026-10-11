struct budget_state {
    unsigned char head[0x2e0];
    int limit;
    int used;
};

extern "C" float forge_budget_fraction_6dd40(budget_state* state, int* out_used, int* out_limit) {
    if (out_used) {
        *out_used = state->used;
    }
    if (out_limit) {
        *out_limit = state->limit;
    }
    if (state->limit > 0) {
        return static_cast<float>(state->used) / static_cast<float>(state->limit);
    }
    return 0.0f;
}
