struct value_slot {
    int kind;
    int reserved4;
    void* pointer;
};

extern "C" char function_3326e0(char* object, void*, value_slot* out) {
    out->kind = 3;
    out->pointer = object + 0xd04;
    return 1;
}
