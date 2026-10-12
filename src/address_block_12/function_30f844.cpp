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

extern "C" char function_30f844(const char* object, long long, parameter_value* out) {
    int count = *reinterpret_cast<const int*>(object + 0x2FC0);
    out->kind = 0;
    out->flag = count > 0;
    return 1;
}
