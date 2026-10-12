struct itecho_state;

struct itecho_dsp {
    itecho_state* state;
};

extern "C" int function_5d31d0(void * state, int index, float value, unsigned char notify);

extern "C" int function_5d3780(itecho_dsp* dsp, int index, float value) {
    return function_5d31d0(dsp->state, index, value, 1);
}
