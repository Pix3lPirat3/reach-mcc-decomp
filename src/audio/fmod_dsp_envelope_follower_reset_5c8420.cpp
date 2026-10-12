struct follower_state {
    unsigned char reserved0[0x220];
    int field_220;
};

struct dsp {
    follower_state* state;
};

extern "C" int fmod_dsp_envelope_follower_reset_5c8420(dsp* unit) {
    unit->state->field_220 = 0;
    return 0;
}
