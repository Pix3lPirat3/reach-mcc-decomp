struct input_block {
    unsigned char reserved0[0xCC];
    int field_CC;
};

struct output_block {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_326ea0(input_block* input, long long, output_block* output) {
    int value = input->field_CC;
    output->kind = 1;
    output->value = value;
    return 1;
}
