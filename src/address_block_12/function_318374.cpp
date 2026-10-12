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

extern "C" char function_318374(const char* object, int index, parameter_value* out) {
    const char* element = nullptr;
    if (index < 0)
        return 0;
    if (index >= *reinterpret_cast<const int*>(object + 0x78))
        return 0;
    if (object[0x28] == 2)
        element = object + (static_cast<long long>(index) << 7) + 0xD8;
    out->address = element;
    out->kind = 3;
    return 1;
}
