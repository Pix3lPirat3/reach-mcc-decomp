struct input_block {
    unsigned char reserved0[0xC0];
    unsigned char field_C0;
};

struct output_block {
    int kind;
    int reserved4;
    char value;
};

extern "C" char function_32a334(input_block* input, long long, output_block* output) {
    unsigned char value = input->field_C0;
    output->kind = 0;
    output->value = static_cast<char>((value >> 4) & 1);
    return 1;
}
