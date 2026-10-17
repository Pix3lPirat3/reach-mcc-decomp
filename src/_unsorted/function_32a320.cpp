struct input_block {
    unsigned char reserved0[0xC0];
    char field_C0;
};

struct output_block {
    int kind;
    int reserved4;
    char value;
};

extern "C" char function_32a320(input_block* input, long long, output_block* output) {
    char value = input->field_C0;
    output->kind = 0;
    output->value = static_cast<char>(value & 1);
    return 1;
}
