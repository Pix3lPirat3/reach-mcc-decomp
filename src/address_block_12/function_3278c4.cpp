struct input_block {
    unsigned char reserved0[0x560];
    int field_560;
};

struct output_block {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_3278c4(input_block* input, long long, output_block* output) {
    int value = input->field_560;
    output->kind = 1;
    output->value = value;
    return 1;
}
