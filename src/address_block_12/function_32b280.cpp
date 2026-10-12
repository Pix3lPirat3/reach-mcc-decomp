struct input_block {
    unsigned char reserved0[0x2A1C0];
    int field_2A1C0;
};

struct output_block {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_32b280(input_block* input, long long, output_block* output) {
    int value = input->field_2A1C0;
    output->kind = 1;
    output->value = value;
    return 1;
}
