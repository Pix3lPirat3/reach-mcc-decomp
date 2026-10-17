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

extern "C" char function_30b284(const char* object, long long, parameter_value* out) {
    int value = *reinterpret_cast<const int*>(object + 0x78);
    out->kind = 1;
    out->number = value;
    return 1;
}
