struct value_slot {
    int kind;
    int reserved4;
    char flag;
};

extern "C" char function_33991c(char* object, void*, value_slot* out) {
    char value = *(object + 0xca0);
    out->kind = 0;
    out->flag = value;
    return 1;
}
