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

extern "C" char function_30f8d0(const char* object, long long, parameter_value* out) {
    int value = *reinterpret_cast<const int*>(object + 0x2FC4);
    out->kind = 1;
    out->number = value;
    return 1;
}
