struct sfxreverb_state;

struct sfxreverb_dsp {
    sfxreverb_state* state;
};

extern "C" int function_60e0a0(void * state, int index, float value, unsigned char notify);

extern "C" int function_60f060(sfxreverb_dsp* dsp, int index, float value) {
    return function_60e0a0(dsp->state, index, value, 1);
}
