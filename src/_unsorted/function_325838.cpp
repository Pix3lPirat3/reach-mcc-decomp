struct input_block {
    unsigned char reserved0[0x12C];
    int field_12C;
};

struct output_block {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_325838(input_block* input, long long, output_block* output) {
    output->value = input->field_12C;
    output->kind = 6;
    return 1;
}
