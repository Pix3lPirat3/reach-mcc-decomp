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

extern "C" char function_31449c(const char* object, long long, parameter_value* out) {
    out->kind = 3;
    out->address = object + 0x198;
    return 1;
}
