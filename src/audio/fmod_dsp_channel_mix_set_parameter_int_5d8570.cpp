struct channel_mix_state {
    unsigned char reserved_0[0x23c8];
    int field_23c8;
};

struct channel_mix_dsp {
    channel_mix_state* state;
};

extern "C" int fmod_dsp_channel_mix_set_parameter_int_5d8570(channel_mix_dsp* dsp, int index, int value) {
    if (index != 0)
        return 0;
    dsp->state->field_23c8 = value;
    return 0;
}
