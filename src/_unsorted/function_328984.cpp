struct input_block {
    unsigned char reserved0[0x700];
    int field_700;
};

struct output_block {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_328984(input_block* input, long long, output_block* output) {
    int value = input->field_700;
    output->kind = 1;
    output->value = value;
    return 1;
}
