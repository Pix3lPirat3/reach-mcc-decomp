struct input_block {
    unsigned char reserved0[0xB4];
    unsigned short field_B4;
};

struct output_block {
    unsigned char reserved0[8];
    void* value;
};

extern "C" long long function_35c3c(void* destination, void* source, long long count);

extern "C" char function_329ef4(input_block* input, long long, output_block* output) {
    function_35c3c(&input->field_B4, output->value, 5);
    return 1;
}
