struct input_block {
    unsigned char reserved0[0x11C];
    int field_11C;
};

struct output_block {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_325790(input_block* input, long long, output_block* output) {
    output->value = input->field_11C;
    output->kind = 6;
    return 1;
}
