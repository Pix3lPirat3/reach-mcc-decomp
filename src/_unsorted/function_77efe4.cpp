struct state_block {
    unsigned char reserved0[0x14];
    int field_14;
    unsigned char reserved18[8];
    int field_20;
};

extern "C" long long function_77ef00(int value);

extern "C" char function_77efe4(state_block* state) {
    if (state->field_20 != 0)
        return 1;
    function_77ef00(state->field_14);
    return 1;
}
