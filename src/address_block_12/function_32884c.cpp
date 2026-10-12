struct pair_block {
    unsigned char reserved0[8];
    void* value;
};

extern "C" long long function_328468(void* input, void* value);

extern "C" char function_32884c(void* input, long long, pair_block* output) {
    function_328468(input, output->value);
    return 1;
}
