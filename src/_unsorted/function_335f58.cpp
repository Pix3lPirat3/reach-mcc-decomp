struct value_slot {
    int kind;
    int reserved4;
    char flag;
};

extern "C" char function_335f58(char* object, void*, value_slot* out) {
    unsigned int flags = *reinterpret_cast<unsigned int*>(object + 0x70);
    out->kind = 0;
    out->flag = (char)(flags >> 13) & 1;
    return 1;
}
