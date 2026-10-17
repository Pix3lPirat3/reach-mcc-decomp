struct value_slot {
    int kind;
    int reserved4;
    char flag;
};

extern "C" char function_339128(char* object, void*, value_slot* out) {
    bool value = *(object + 0xb58) == 0;
    out->kind = 0;
    out->flag = value;
    return 1;
}
