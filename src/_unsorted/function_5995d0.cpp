struct compressor_state {
    unsigned char reserved0[0x354];
    float field_354;
    float field_358;
    float field_35c;
    float field_360;
    float field_364;
};

struct compressor_dsp {
    compressor_state* state;
};

extern "C" long long function_5995d0(compressor_dsp* dsp, int index, float value) {
    compressor_state* state = dsp->state;
    switch (index) {
    case 0:
        state->field_358 = value;
        return 0;
    case 1:
        state->field_35c = value;
        return 0;
    case 2:
        state->field_354 = value;
        return 0;
    case 3:
        state->field_360 = value;
        return 0;
    case 4:
        state->field_364 = value;
        return 0;
    default:
        return 0x1F;
    }
}
