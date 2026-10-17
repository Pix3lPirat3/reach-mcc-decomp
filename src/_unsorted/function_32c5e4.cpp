struct input_block {
    unsigned char reserved0[0x15B0];
    int field_15B0;
};

struct output_block {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_32c5e4(input_block* input, long long, output_block* output) {
    int value = input->field_15B0;
    output->kind = 1;
    output->value = value;
    return 1;
}
