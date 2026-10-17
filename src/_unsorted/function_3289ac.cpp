struct input_block {
    unsigned char reserved0[0x708];
    int field_708;
};

struct output_block {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_3289ac(input_block* input, long long, output_block* output) {
    int value = input->field_708;
    output->kind = 1;
    output->value = value;
    return 1;
}
