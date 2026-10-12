struct normalize_state {
    unsigned char reserved0[0x210];
    float gain_210;
    float gain_214;
};

struct dsp {
    normalize_state* state;
};

extern "C" int fmod_dsp_normalize_reset_5d8d70(dsp* unit) {
    normalize_state* state = unit->state;
    state->gain_214 = 1.0f;
    state->gain_210 = 1.0f;
    return 0;
}
