struct send_state {
    unsigned char reserved_0[0x210];
    int field_210;
    unsigned char reserved_214[0x4];
    int field_218;
};

struct send_dsp {
    send_state* state;
};

extern "C" int fmod_dsp_send_reset_5f81d0(send_dsp* dsp) {
    send_state* state = dsp->state;
    state->field_210 = state->field_218;
    return 0;
}
