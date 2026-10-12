struct value_slot {
    int kind;
    int reserved4;
    char flag;
};

extern "C" char function_33b7e8(char* object, void*, value_slot* out) {
    char value = *(object + 0x19720);
    out->kind = 0;
    out->flag = value;
    return 1;
}
