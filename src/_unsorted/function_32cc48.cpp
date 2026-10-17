struct value_slot {
    int kind;
    int reserved4;
    void* pointer;
};

extern "C" char function_32cc48(char* object, void*, value_slot* out) {
    out->kind = 3;
    out->pointer = object + 0x1618;
    return 1;
}
