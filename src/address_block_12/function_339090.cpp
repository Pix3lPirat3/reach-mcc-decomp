struct value_slot {
    int kind;
    int reserved4;
    char flag;
};

extern "C" char function_339090(char* object, void*, value_slot* out) {
    bool value = *reinterpret_cast<int*>(object + 0xb5c) == 2;
    out->kind = 0;
    out->flag = value;
    return 1;
}
