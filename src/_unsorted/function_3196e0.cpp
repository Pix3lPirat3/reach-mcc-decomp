struct parameter_value {
    int kind;
    int reserved4;
    int number;
};

extern "C" char function_3196e0(char* object, long long, const parameter_value* input) {
    int value = input->number;
    if (value < 0)
        value = 0;
    *reinterpret_cast<int*>(object + 0x1188) = value;
    return 1;
}
