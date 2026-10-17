struct value_slot {
    int kind;
    int reserved4;
    void* pointer;
};

extern "C" char function_335a28(char* object, void*, value_slot* out) {
    out->kind = 12;
    out->pointer = object + 0x198;
    return 1;
}
