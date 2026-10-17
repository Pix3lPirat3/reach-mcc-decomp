struct input_block {
    unsigned char reserved0[0xA4];
    int field_A4;
};

struct output_block {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_329788(input_block* input, long long, output_block* output) {
    int value = input->field_A4;
    output->kind = 1;
    output->value = value;
    return 1;
}
