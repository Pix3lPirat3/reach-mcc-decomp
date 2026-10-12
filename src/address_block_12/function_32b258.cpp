struct input_block {
    unsigned char reserved0[1];
};

struct output_block {
    int kind;
    int reserved4;
    unsigned long long value;
};

extern "C" char function_32b258(input_block* input, long long, output_block* output) {
    output->value = *reinterpret_cast<unsigned long long*>(reinterpret_cast<unsigned char*>(input) + 0x2A1C4);
    output->kind = 11;
    return 1;
}
