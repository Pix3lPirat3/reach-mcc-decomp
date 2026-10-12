struct input_block {
    unsigned char reserved0[0x98];
    int field_98;
};

struct output_block {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_329760(input_block* input, long long, output_block* output) {
    output->value = input->field_98;
    output->kind = 6;
    return 1;
}
