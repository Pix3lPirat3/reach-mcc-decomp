struct parameter_value {
    int kind;
    int reserved4;
    union {
        char flag;
        int number;
        long long wide;
        const void* address;
    };
};

extern "C" char function_3179b0(const char* object, long long, parameter_value* out) {
    out->kind = 9;
    out->address = object + 0x80;
    return 1;
}
