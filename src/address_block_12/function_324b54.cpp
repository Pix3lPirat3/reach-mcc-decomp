struct input_block {
    unsigned char reserved0[0x278];
    int field_278;
};

struct output_block {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_324b54(input_block* input, long long, output_block* output) {
    int value = input->field_278;
    output->kind = 1;
    output->value = value;
    return 1;
}
