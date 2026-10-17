struct input_block {
    unsigned char reserved0[0x274];
    int field_274;
};

struct output_block {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_324b30(input_block* input, long long, output_block* output) {
    int value = input->field_274;
    output->kind = 1;
    output->value = value;
    return 1;
}
