struct value_slot {
    int kind;
    int reserved4;
    void* pointer;
};

extern "C" char function_33244c(char* object, void*, value_slot* out) {
    out->pointer = *reinterpret_cast<void**>(object + 0x78);
    out->kind = 8;
    return 1;
}
