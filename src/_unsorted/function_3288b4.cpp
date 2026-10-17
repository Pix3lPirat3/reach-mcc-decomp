struct input_block {
    unsigned char reserved0[0x374];
    int field_374;
};

struct output_block {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_3288b4(input_block* input, long long, output_block* output) {
    int value = input->field_374;
    output->kind = 1;
    output->value = value;
    return 1;
}
