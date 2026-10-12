struct value_slot {
    int kind;
    int reserved4;
    char flag;
};

extern "C" char function_33906c(char* object, void*, value_slot* out) {
    char result;
    if (*reinterpret_cast<int*>(object + 0xb5c) == 4 || *reinterpret_cast<int*>(object + 0xb68) == 20)
        result = 1;
    else
        result = 0;
    out->kind = 0;
    out->flag = result;
    return 1;
}
