struct simple_filter_state {
    unsigned char reserved_0[0x318];
    float field_318;
};

struct simple_filter_dsp {
    simple_filter_state* state;
};

extern "C" int fmod_dsp_simple_filter_set_parameter_float_5e6180(simple_filter_dsp* dsp, int index, float value) {
    if (index != 0)
        return 0;
    dsp->state->field_318 = value;
    return 0;
}
