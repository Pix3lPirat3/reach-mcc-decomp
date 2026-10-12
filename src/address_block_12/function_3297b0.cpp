struct input_block {
    unsigned char reserved0[0x88];
    int field_88;
};

struct output_block {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_3297b0(input_block* input, long long, output_block* output) {
    int value = input->field_88;
    output->kind = 1;
    output->value = value;
    return 1;
}
