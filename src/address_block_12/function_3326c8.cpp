struct value_slot {
    int kind;
    int reserved4;
    void* pointer;
};

extern "C" char function_3326c8(char* object, void*, value_slot* out) {
    out->kind = 3;
    out->pointer = object + 0xcde;
    return 1;
}
