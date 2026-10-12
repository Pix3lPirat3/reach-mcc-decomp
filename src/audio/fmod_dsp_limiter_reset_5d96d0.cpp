struct limiter_state {
    unsigned char reserved0[0x210];
    float gains[32];
};

struct dsp {
    limiter_state* state;
};

extern "C" int fmod_dsp_limiter_reset_5d96d0(dsp* unit) {
    limiter_state* state = unit->state;
    for (int i = 0; i < 32; i++)
        state->gains[i] = 1.0f;
    return 0;
}
