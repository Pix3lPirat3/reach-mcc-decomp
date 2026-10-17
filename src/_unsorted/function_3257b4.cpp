struct input_block {
    unsigned char reserved0[0x120];
    int field_120;
};

struct output_block {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_3257b4(input_block* input, long long, output_block* output) {
    output->value = input->field_120;
    output->kind = 6;
    return 1;
}
