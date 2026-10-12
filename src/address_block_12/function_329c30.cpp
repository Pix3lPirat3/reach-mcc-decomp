struct input_block {
    unsigned char reserved0[0x98];
    char field_98;
};

struct output_block {
    int kind;
    int reserved4;
    char value;
};

extern "C" char function_329c30(input_block* input, long long, output_block* output) {
    char flags = input->field_98;
    input->field_98 = output->value == 0 ? static_cast<char>(flags & ~2) : static_cast<char>(flags | 2);
    return 1;
}
