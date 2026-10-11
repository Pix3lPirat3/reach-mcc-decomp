struct threeeq_state {
    unsigned char reserved_0[0x2574];
    int field_2574;
};

struct threeeq_dsp {
    threeeq_state* state;
};

extern "C" int fmod_dsp_threeeq_set_parameter_int_5ec920(threeeq_dsp* dsp, int index, int value) {
    if (index != 5)
        return 0;
    dsp->state->field_2574 = value;
    return 0;
}
