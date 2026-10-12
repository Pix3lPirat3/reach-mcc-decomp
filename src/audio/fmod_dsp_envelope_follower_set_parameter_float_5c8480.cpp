struct follower_state {
    unsigned char reserved0[0x228];
    float value_228;
    float value_22c;
};

struct dsp {
    follower_state* state;
};

extern "C" int fmod_dsp_envelope_follower_set_parameter_float_5c8480(dsp* unit, int index, float value) {
    follower_state* state = unit->state;
    switch (index) {
    case 0:
        state->value_228 = value;
        return 0;
    case 1:
        state->value_22c = value;
        return 0;
    case 2:
        return 0x44;
    default:
        return 0x1F;
    }
}
