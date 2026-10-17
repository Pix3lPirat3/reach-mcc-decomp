extern "C" void* function_912c10(void* base, void* value);

struct argument {
    unsigned char reserved0[0x20];
    void* value;
};

struct result_block {
    unsigned char reserved0[0x38];
    float result;
};

extern "C" float function_912e00(char* self, argument* arg) {
    function_912c10(self - 0x10, arg->value);
    return ((result_block*)self)->result;
}
