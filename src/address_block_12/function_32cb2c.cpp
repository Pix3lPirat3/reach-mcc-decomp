struct input_block {
    unsigned char reserved0[0x15B4];
    int field_15B4;
};

struct output_block {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_32cb2c(input_block* input, long long, output_block* output) {
    int value = input->field_15B4;
    output->kind = 1;
    output->value = value;
    return 1;
}
