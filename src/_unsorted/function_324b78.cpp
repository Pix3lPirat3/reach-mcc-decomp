struct input_block {
    unsigned char reserved0[0x22C];
    unsigned int field_22C;
};

struct output_block {
    int kind;
    int reserved4;
    char value;
};

extern "C" char function_324b78(input_block* input, long long, output_block* output) {
    unsigned int flags = input->field_22C;
    output->kind = 0;
    output->value = static_cast<char>((flags >> 14) & 1);
    return 1;
}
