struct pan_state {
    unsigned char reserved0[0x58];
    void* field_58;
    void* field_60;
};

extern "C" int function_615990(pan_state* state) {
    if (state->field_58 == 0)
        return 0;
    if (state->field_60 == 0)
        return 0;
    return 2;
}
