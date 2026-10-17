struct input_block {
    unsigned char reserved0[0xC0];
    unsigned long long field_C0;
};

struct output_block {
    int kind;
    int reserved4;
    unsigned long long value;
};

extern "C" char function_32a514(input_block* input, long long, output_block* output) {
    output->value = input->field_C0;
    output->kind = 11;
    return 1;
}
