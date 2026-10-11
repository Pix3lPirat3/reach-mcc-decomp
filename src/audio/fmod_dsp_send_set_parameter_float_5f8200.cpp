struct send_state {
    unsigned char reserved_0[0x58];
    int field_58;
    unsigned char reserved_5c[0x1bc];
    float field_218;
    int field_21c;
};

struct send_dsp {
    send_state* state;
};

extern "C" int fmod_dsp_send_set_parameter_float_5f8200(send_dsp* dsp, int index, float value) {
    send_state* state = dsp->state;
    if (index != 1)
        return 0;
    state->field_21c = state->field_58;
    state->field_218 = value;
    return 0;
}
