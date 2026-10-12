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

extern "C" char function_3119d4(const char* object, long long, parameter_value* out) {
    out->kind = 3;
    out->address = object + 0xFA;
    return 1;
}
