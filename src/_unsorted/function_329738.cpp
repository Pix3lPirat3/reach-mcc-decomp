struct input_block {
    unsigned char reserved0[0x8C];
    int field_8C;
};

struct output_block {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_329738(input_block* input, long long, output_block* output) {
    output->value = input->field_8C;
    output->kind = 6;
    return 1;
}
