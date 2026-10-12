struct input_block {
    unsigned char reserved0[0x22C];
    int field_22C;
};

struct output_block {
    int kind;
    int reserved4;
    char value;
};

extern "C" char function_324b90(input_block* input, long long, output_block* output) {
    int flags = input->field_22C;
    input->field_22C = output->value == 0 ? flags & ~0x4000 : flags | 0x4000;
    return 1;
}
