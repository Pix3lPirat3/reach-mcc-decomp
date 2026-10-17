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

extern "C" char function_30b0ac(const char* object, long long, parameter_value* out) {
    char value = *(object + 0xEC2);
    out->kind = 0;
    out->flag = value;
    return 1;
}
