struct input_block {
    unsigned char reserved0[0x84];
    int field_84;
};

struct output_block {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_329724(input_block* input, long long, output_block* output) {
    output->value = input->field_84;
    output->kind = 6;
    return 1;
}
