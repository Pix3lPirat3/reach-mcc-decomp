struct input_block {
    unsigned char reserved0[0x112A08];
    int field_112A08;
};

struct output_block {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_32b958(input_block* input, long long, output_block* output) {
    int value = input->field_112A08;
    output->kind = 1;
    output->value = value;
    return 1;
}
