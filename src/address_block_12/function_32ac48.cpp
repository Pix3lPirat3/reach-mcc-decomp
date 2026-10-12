struct output_block {
    int kind;
    int reserved4;
    int value;
};

extern "C" int function_32aa74(void);

extern "C" char function_32ac48(long long, long long, output_block* output) {
    output->value = function_32aa74();
    output->kind = 1;
    return 1;
}
