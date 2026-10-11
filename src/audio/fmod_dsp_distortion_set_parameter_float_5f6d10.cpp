struct distortion_state {
    unsigned char reserved_0[0x218];
    float field_218;
};

struct distortion_dsp {
    distortion_state* state;
};

extern "C" int fmod_dsp_distortion_set_parameter_float_5f6d10(distortion_dsp* dsp, long long, float value) {
    dsp->state->field_218 = value;
    return 0;
}
