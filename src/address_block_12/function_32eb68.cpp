struct value_slot {
    int kind;
    int reserved4;
    int number;
};

extern "C" char function_32eb68(char* object, void*, value_slot* out) {
    int value = *reinterpret_cast<int*>(object + 0x78) + 1;
    out->kind = 1;
    out->number = value;
    return 1;
}
