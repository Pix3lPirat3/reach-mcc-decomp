extern "C" void * function_914240(void * base, void * out, void* value);

struct argument {
    unsigned char reserved0[0x20];
    void* value;
};

struct result_block {
    unsigned char reserved0[0x18];
    float result;
};

extern "C" float function_914560(char* self, argument* arg) {
    long long scratch;
    function_914240(self - 0x20, &scratch, arg->value);
    return ((result_block*)self)->result;
}
