struct input_block {
    unsigned char reserved0[0x8920];
    unsigned long long field_8920;
};

struct output_block {
    int kind;
    int reserved4;
    unsigned long long value;
};

extern "C" char function_321970(input_block* input, long long, output_block* output) {
    output->value = input->field_8920;
    output->kind = 4;
    return 1;
}
