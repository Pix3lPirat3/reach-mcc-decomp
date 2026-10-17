struct input_block {
    unsigned char reserved0[0x704];
    int field_704;
};

struct output_block {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_328998(input_block* input, long long, output_block* output) {
    int value = input->field_704;
    output->kind = 1;
    output->value = value;
    return 1;
}
