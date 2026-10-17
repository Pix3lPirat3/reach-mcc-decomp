struct net_state {
    unsigned char reserved0[0x4738];
    int field_4738;
    int field_473C;
    unsigned char reserved4740[0x5C7B8];
    int field_60EF8;
    unsigned char reserved60EFC[0x5B4];
    int field_614B0;
    unsigned int field_614B4;
    unsigned int field_614B8;
};

extern "C" unsigned int function_397178(net_state* state) {
    int value = state->field_60EF8;
    state->field_614B0 = state->field_614B0 + 1;
    unsigned long long offset = (unsigned int)(value - 6);
    if ((unsigned int)offset <= 3)
        return (unsigned int)offset;
    state->field_4738 = 0;
    state->field_473C = 0;
    state->field_614B4 = 0xFFFFFFFF;
    state->field_614B8 = 0xFFFFFFFF;
    return 0xFFFFFFFF;
}
