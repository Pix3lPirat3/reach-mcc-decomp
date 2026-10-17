struct input_block {
    unsigned char reserved0[0x208];
    int field_208;
};

struct output_block {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_324acc(input_block* input, long long, output_block* output) {
    output->value = input->field_208;
    output->kind = 6;
    return 1;
}
