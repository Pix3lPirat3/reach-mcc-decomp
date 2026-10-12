struct input_block {
    unsigned char reserved0[1];
};

struct output_block {
    int kind;
    int reserved4;
    unsigned long long value;
};

extern "C" char function_326184(input_block* input, long long, output_block* output) {
    output->kind = 9;
    output->value = reinterpret_cast<unsigned long long>(reinterpret_cast<unsigned char*>(input) + 0xB0);
    return 1;
}
