struct input_block {
    unsigned char reserved0[0x308];
    unsigned long long field_308;
};

struct output_block {
    int kind;
    int reserved4;
    unsigned long long value;
};

extern "C" char function_320740(input_block* input, long long, output_block* output) {
    output->value = input->field_308;
    output->kind = 4;
    return 1;
}
