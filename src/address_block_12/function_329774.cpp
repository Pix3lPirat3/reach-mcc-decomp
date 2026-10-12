struct input_block {
    unsigned char reserved0[0x9C];
    int field_9C;
};

struct output_block {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_329774(input_block* input, long long, output_block* output) {
    output->value = input->field_9C;
    output->kind = 6;
    return 1;
}
