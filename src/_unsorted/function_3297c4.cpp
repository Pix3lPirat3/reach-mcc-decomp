struct input_block {
    unsigned char reserved0[0x94];
    int field_94;
};

struct output_block {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_3297c4(input_block* input, long long, output_block* output) {
    int value = input->field_94;
    output->kind = 1;
    output->value = value;
    return 1;
}
