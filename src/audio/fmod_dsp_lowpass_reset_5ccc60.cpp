struct lowpass_state {
    unsigned char reserved_0[0x224];
    unsigned char history[512];
};

struct lowpass_dsp {
    lowpass_state* state;
};

extern "C" long long function_78932a(void* destination, int value, long long size);

extern "C" int fmod_dsp_lowpass_reset_5ccc60(lowpass_dsp* dsp) {
    function_78932a(dsp->state->history, 0, 0x200);
    return 0;
}
