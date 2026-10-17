struct output_block {
    int kind;
    int reserved4;
    int value;
};

extern "C" int function_32aa98(void);

extern "C" char function_32acc8(long long, long long, output_block* output) {
    output->value = function_32aa98();
    output->kind = 1;
    return 1;
}
