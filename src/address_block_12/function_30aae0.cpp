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

extern "C" char function_30aae0(const char* object, long long, parameter_value* out) {
    const char* first;
    const char* second;
    if (object[0xEC0] == 0) {
none_first:
        first = nullptr;
    } else {
        first = object + 0xC9;
        if (object[0xC8] == 0)
            goto none_first;
    }
    if (first == nullptr) {
none_second:
        second = nullptr;
    } else {
        second = first + 0xCC1;
        if (*second == 0)
            goto none_second;
    }
    out->kind = 0;
    out->flag = second != nullptr;
    return 1;
}
