struct input_block {
    unsigned char reserved0[0xA0];
    unsigned long long field_A0;
};

struct output_block {
    int kind;
    int reserved4;
    unsigned long long value;
};

extern "C" char function_329b6c(input_block* input, long long, output_block* output) {
    output->value = input->field_A0;
    output->kind = 10;
    return 1;
}
