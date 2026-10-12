struct input_block {
    unsigned char reserved0[0xA8];
    int field_A8;
};

struct output_block {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_32979c(input_block* input, long long, output_block* output) {
    int value = input->field_A8;
    output->kind = 1;
    output->value = value;
    return 1;
}
