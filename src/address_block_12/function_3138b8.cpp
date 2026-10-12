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

extern "C" char function_3138b8(const char* object, long long, parameter_value* out) {
    out->kind = 3;
    out->address = object + 0xA2;
    return 1;
}
