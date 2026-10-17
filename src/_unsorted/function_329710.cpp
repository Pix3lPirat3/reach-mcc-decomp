struct input_block {
    unsigned char reserved0[0x74];
    int field_74;
};

struct output_block {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_329710(input_block* input, long long, output_block* output) {
    output->value = input->field_74;
    output->kind = 6;
    return 1;
}
