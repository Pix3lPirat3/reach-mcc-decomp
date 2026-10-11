struct oscillator_state {
    unsigned char reserved_0[0x22c];
    int field_22c;
};

struct oscillator_dsp {
    oscillator_state* state;
};

extern "C" int fmod_dsp_oscillator_set_parameter_int_59bf80(oscillator_dsp* dsp, int index, int value) {
    if (index != 0)
        return 0;
    dsp->state->field_22c = value;
    return 0;
}
