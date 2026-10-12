extern "C" void* function_912c10(void* base, void* value);

struct argument {
    unsigned char reserved0[0x10];
    void* value;
};

struct result_block {
    unsigned char reserved0[0x30];
    float result;
};

extern "C" float function_912dd0(char* self, argument* arg) {
    function_912c10(self - 0x18, arg->value);
    return ((result_block*)self)->result;
}
