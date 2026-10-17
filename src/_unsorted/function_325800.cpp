struct pair_block {
    unsigned char reserved0[8];
    void* value;
};

extern "C" void function_325414(void* input, void* value);

extern "C" char function_325800(void* input, long long, pair_block* output) {
    function_325414(input, output->value);
    return 1;
}
