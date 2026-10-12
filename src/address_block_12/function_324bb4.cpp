struct input_block {
    unsigned char reserved0[0x1F8];
    char field_1F8;
};

struct output_block {
    int kind;
    int reserved4;
    char value;
};

extern "C" char function_324bb4(input_block* input, long long, output_block* output) {
    char value = input->field_1F8;
    output->kind = 0;
    output->value = value;
    return 1;
}
