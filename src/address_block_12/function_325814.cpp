struct input_block {
    unsigned char reserved0[0x128];
    int field_128;
};

struct output_block {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_325814(input_block* input, long long, output_block* output) {
    output->value = input->field_128;
    output->kind = 6;
    return 1;
}
