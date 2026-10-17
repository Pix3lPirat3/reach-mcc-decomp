struct input_block {
    unsigned char reserved0[0x90];
    unsigned long long field_90;
};

struct output_block {
    int kind;
    int reserved4;
    unsigned long long value;
};

extern "C" char function_329b94(input_block* input, long long, output_block* output) {
    output->value = input->field_90;
    output->kind = 8;
    return 1;
}
