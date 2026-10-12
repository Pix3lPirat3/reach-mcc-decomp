struct compressor_state {
    unsigned char reserved0[0x224];
    unsigned char history[0x100];
    unsigned char reserved324[0x24];
    unsigned long long field_348;
};

struct compressor_dsp {
    compressor_state* state;
};

extern "C" void* function_78932a(void* target, int value, unsigned long long count);

extern "C" int function_599540(compressor_dsp* dsp) {
    compressor_state* state = dsp->state;
    function_78932a(state->history, 0, 0x100);
    state->field_348 = 0;
    return 0;
}
