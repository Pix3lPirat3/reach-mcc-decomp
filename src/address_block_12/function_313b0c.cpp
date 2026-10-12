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

extern "C" char function_313b0c(const char* object, long long, parameter_value* out) {
    bool valid = *reinterpret_cast<const int*>(object + 0xC0) != -1;
    out->kind = 0;
    out->flag = valid;
    return 1;
}
