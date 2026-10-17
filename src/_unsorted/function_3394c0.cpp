struct value_slot {
    int kind;
    int reserved4;
    char flag;
};

extern "C" char function_3394c0(char* object, void*, value_slot* out) {
    char value = *(object + 0x8b4);
    out->kind = 0;
    out->flag = value;
    return 1;
}
