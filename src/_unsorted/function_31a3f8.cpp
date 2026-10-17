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

extern "C" char function_31a3f8(const char* object, long long, parameter_value* out) {
    int value = *reinterpret_cast<const int*>(object + 0xA0);
    out->kind = 6;
    out->number = value;
    return 1;
}
