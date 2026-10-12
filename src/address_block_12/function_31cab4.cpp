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

extern "C" int function_31c198(const void* object, char value);

struct parameter_input {
    long long reserved0;
    char value;
};

extern "C" char function_31cab4(const void* object, long long, const parameter_input* input) {
    function_31c198(object, input->value);
    return 1;
}
