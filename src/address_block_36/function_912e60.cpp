extern "C" void* function_912c10(void* base, void* value);

struct argument {
    unsigned char reserved0[0x20];
    void* value;
};

struct result_block {
    unsigned char reserved0[0x48];
    float result;
};

extern "C" float function_912e60(result_block* self, argument* arg) {
    function_912c10(self, arg->value);
    return self->result;
}
