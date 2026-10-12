struct scoring_state {
    int field_0;
    unsigned char field_4[124];
};

extern "C" void * function_78932a(void* destination, int value, unsigned long long size);

extern "C" scoring_state* function_1916f8(scoring_state* state) {
    state->field_0 = -1;
    function_78932a(state->field_4, 0, 0x7c);
    return state;
}
