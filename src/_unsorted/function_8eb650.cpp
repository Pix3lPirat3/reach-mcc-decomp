struct builder_state {
    void* field_0;
    int field_8;
    unsigned int field_C;
    unsigned char reserved10[0x10];
    void* field_20;
    int field_28;
    unsigned int field_2C;
};

extern "C" void function_8eb470(builder_state* state, void* second);

extern "C" builder_state* function_8eb650(builder_state* state, void* second) {
    state->field_C = 0x80000000;
    state->field_0 = 0;
    state->field_8 = 0;
    state->field_20 = 0;
    state->field_28 = 0;
    state->field_2C = 0x80000000;
    function_8eb470(state, second);
    return state;
}
