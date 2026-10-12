struct value_slot {
    int kind;
    int reserved4;
    char flag;
};

extern "C" char function_335f6c(char* object, void*, value_slot* slot) {
    int flags = *reinterpret_cast<int*>(object + 0x70);
    *reinterpret_cast<int*>(object + 0x70) = slot->flag == 0 ? flags & ~0x2000 : flags | 0x2000;
    return 1;
}
