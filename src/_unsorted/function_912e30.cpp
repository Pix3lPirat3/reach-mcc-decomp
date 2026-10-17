extern "C" void* function_912c10(void* base, void* value);

struct argument {
    unsigned char reserved0[0x10];
    void* value;
};

struct result_block {
    unsigned char reserved0[0x40];
    float result;
};

extern "C" float function_912e30(char* self, argument* arg) {
    function_912c10(self - 8, arg->value);
    return ((result_block*)self)->result;
}
