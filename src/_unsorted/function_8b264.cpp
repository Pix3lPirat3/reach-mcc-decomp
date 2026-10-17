struct cleared_state {
    int field_0;
    unsigned char reserved4[4];
    long long field_8;
    int field_10;
    unsigned char reserved14[4];
    long long field_18;
    int field_20;
    unsigned char reserved24[4];
    long long field_28;
    int field_30;
    unsigned char reserved34[4];
    long long field_38;
    unsigned char reserved40[0x10];
    long long field_50;
    int field_58;
};

extern "C" cleared_state* function_8b264(cleared_state* state) {
    state->field_8 = 0;
    state->field_0 = 0;
    state->field_18 = 0;
    state->field_10 = 0;
    state->field_28 = 0;
    state->field_20 = 0;
    state->field_38 = 0;
    state->field_30 = 0;
    state->field_50 = 0;
    state->field_58 = 0;
    return state;
}
