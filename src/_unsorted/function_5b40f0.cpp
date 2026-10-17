struct inner_state {
    unsigned char reserved0[0x30];
    int field_30;
};

struct outer_state {
    unsigned char reserved0[0x10788];
    inner_state* field_10788;
};

struct dsp_object {
    unsigned char reserved0[0x5F];
    char field_5f;
    unsigned char reserved60[0x50];
    outer_state* field_b0;
};

extern "C" int function_5b40f0(dsp_object* dsp, char value, char notify) {
    if (notify != 0 && value != dsp->field_5f)
        dsp->field_b0->field_10788->field_30 = 1;
    dsp->field_5f = value;
    return 0;
}
