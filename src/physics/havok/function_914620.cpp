extern "C" void * function_914240(void * base, void * out, void * value);

struct result_block {
    unsigned char reserved0[0x38];
    float result;
};

extern "C" float function_914620(result_block* self, char* arg) {
    long long scratch;
    function_914240((char*)self, &scratch, arg + arg[5]);
    return self->result;
}
