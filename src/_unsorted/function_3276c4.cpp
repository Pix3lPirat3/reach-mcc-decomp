struct input_block {
    unsigned char reserved0[0x55C];
    int field_55C;
};

struct output_block {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_3276c4(input_block* input, long long, output_block* output) {
    int value = input->field_55C;
    output->kind = 1;
    output->value = value;
    return 1;
}
