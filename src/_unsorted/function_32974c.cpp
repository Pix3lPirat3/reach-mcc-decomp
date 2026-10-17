struct input_block {
    unsigned char reserved0[0x90];
    int field_90;
};

struct output_block {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_32974c(input_block* input, long long, output_block* output) {
    output->value = input->field_90;
    output->kind = 6;
    return 1;
}
