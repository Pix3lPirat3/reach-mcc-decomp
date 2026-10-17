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

extern "C" char function_30bf20(const char* object, long long, parameter_value* out) {
    out->kind = 9;
    out->address = object + 0x370;
    return 1;
}
