struct input_block {
    unsigned char reserved0[0x98];
    unsigned char field_98;
};

struct output_block {
    int kind;
    int reserved4;
    char value;
};

extern "C" char function_329c18(input_block* input, long long, output_block* output) {
    unsigned char value = input->field_98;
    output->kind = 0;
    output->value = static_cast<char>((value >> 1) & 1);
    return 1;
}
