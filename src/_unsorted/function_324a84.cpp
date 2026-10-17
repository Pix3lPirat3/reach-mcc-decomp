struct input_block {
    unsigned char reserved0[0x200];
    int field_200;
};

struct output_block {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_324a84(input_block* input, long long, output_block* output) {
    output->value = input->field_200;
    output->kind = 6;
    return 1;
}
