struct input_block {
    unsigned char reserved0[0xC8];
    int field_C8;
};

struct output_block {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_326e7c(input_block* input, long long, output_block* output) {
    int value = input->field_C8;
    output->kind = 1;
    output->value = value;
    return 1;
}
