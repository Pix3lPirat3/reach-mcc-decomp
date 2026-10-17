struct input_block {
    unsigned char reserved0[0x128];
    char field_128;
};

struct output_block {
    int kind;
    int reserved4;
    char value;
};

extern "C" char function_323698(input_block* input, long long, output_block* output) {
    char value = input->field_128;
    output->kind = 0;
    output->value = value;
    return 1;
}
