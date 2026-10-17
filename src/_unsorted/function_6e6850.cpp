struct state_block {
    unsigned char reserved0[0x24];
    int field_24;
    unsigned int field_28;
    unsigned char reserved2c[0xC];
    unsigned int field_38;
    unsigned char reserved3c[0x24];
    int field_60;
};

extern "C" char function_6e6850(long long, state_block* state) {
    state->field_24 = 0;
    state->field_60 = 0;
    state->field_28 = 0xFFFFFFFF;
    state->field_38 = 0xFFFFFFFF;
    return 1;
}
