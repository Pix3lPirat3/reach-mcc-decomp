struct input_block {
    unsigned char reserved0[0x4AF4];
    int field_4AF4;
};

struct output_block {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_321d98(input_block* input, long long, output_block* output) {
    int value = input->field_4AF4;
    output->kind = 1;
    output->value = value;
    return 1;
}
