struct input_block {
    unsigned char reserved0[0x20C];
    int field_20C;
};

struct output_block {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_324af0(input_block* input, long long, output_block* output) {
    output->value = input->field_20C;
    output->kind = 6;
    return 1;
}
