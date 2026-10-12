struct value_slot {
    int kind;
    int reserved4;
    void* pointer;
};

extern "C" char function_332460(char* object, void*, value_slot* out) {
    out->kind = 11;
    out->pointer = *reinterpret_cast<void**>(object + 0x80);
    return 1;
}
