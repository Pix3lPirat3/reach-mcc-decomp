struct state_object {
    unsigned char reserved0[0x58];
    unsigned char field_58;
    unsigned char reserved59[0x37];
    int field_90;
    unsigned char reserved94[0x21];
    unsigned char field_B5;
};

extern "C" void function_8c9ef0(state_object* state) {
    state->field_90 = 0;
    state->field_58 = 0;
    state->field_B5 = 0;
}
