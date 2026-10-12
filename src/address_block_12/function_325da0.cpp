struct input_block {
    unsigned char reserved0[0x115];
    char field_115;
};

struct output_block {
    int kind;
    int reserved4;
    char value;
};

extern "C" char function_325da0(input_block* input, long long, output_block* output) {
    char value = input->field_115;
    output->kind = 0;
    output->value = value;
    return 1;
}
