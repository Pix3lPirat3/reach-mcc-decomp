struct pan_state {
    unsigned char reserved_0[0x219];
    unsigned char field_219;
};

struct pan_dsp {
    pan_state* state;
};

extern "C" int fmod_dsp_pan_reset_5de910(pan_dsp* dsp) {
    dsp->state->field_219 = 1;
    return 0;
}
