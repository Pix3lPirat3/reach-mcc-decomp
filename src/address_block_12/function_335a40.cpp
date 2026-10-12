struct value_slot {
    int kind;
    int reserved4;
    void* pointer;
};

extern "C" char function_335a40(char* object, void*, value_slot* out) {
    out->kind = 12;
    out->pointer = object + 0x1e4;
    return 1;
}
