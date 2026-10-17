struct input_block {
    unsigned char reserved0[0x24F4];
    int field_24F4;
};

struct output_block {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_3223c8(input_block* input, long long, output_block* output) {
    int value = input->field_24F4;
    output->kind = 1;
    output->value = value;
    return 1;
}
