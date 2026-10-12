struct input_block {
    unsigned char reserved0[0xC8];
    unsigned short field_C8;
};

struct output_block {
    unsigned char reserved0[8];
    void* value;
};

extern "C" long long function_35c3c(void* destination, void* source, long long count);

extern "C" char function_329ed0(input_block* input, long long, output_block* output) {
    function_35c3c(&input->field_C8, output->value, 16);
    return 1;
}
