struct input_block {
    unsigned char reserved0[0x204];
    int field_204;
};

struct output_block {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_324aa8(input_block* input, long long, output_block* output) {
    output->value = input->field_204;
    output->kind = 6;
    return 1;
}
