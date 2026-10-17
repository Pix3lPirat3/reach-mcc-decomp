struct input_block {
    unsigned char reserved0[0x98];
    unsigned long long field_98;
};

struct output_block {
    int kind;
    int reserved4;
    unsigned long long value;
};

extern "C" char function_322fd4(input_block* input, long long, output_block* output) {
    output->value = input->field_98;
    output->kind = 11;
    return 1;
}
