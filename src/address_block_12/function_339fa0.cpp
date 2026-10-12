struct value_slot {
    int kind;
    int reserved4;
    void* pointer;
};

extern "C" char function_339fa0(char* object, void*, value_slot* out) {
    out->kind = 12;
    out->pointer = object + 0x2b0;
    return 1;
}
