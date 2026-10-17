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

extern "C" char function_316a64(const char* object, long long, parameter_value* out) {
    out->wide = *reinterpret_cast<const long long*>(object + 0x78);
    out->kind = 4;
    return 1;
}
