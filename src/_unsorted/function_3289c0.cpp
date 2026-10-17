struct input_block {
    unsigned char reserved0[0x70C];
    int field_70C;
};

struct output_block {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_3289c0(input_block* input, long long, output_block* output) {
    int value = input->field_70C;
    output->kind = 1;
    output->value = value;
    return 1;
}
