struct input_block {
    unsigned char reserved0[0x12D0];
    int field_12D0;
};

struct output_block {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_32ab94(input_block* input, long long, output_block* output) {
    int value = input->field_12D0;
    output->kind = 1;
    output->value = value;
    return 1;
}
