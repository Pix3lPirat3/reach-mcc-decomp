struct value_slot {
    int kind;
    int reserved4;
    void* pointer;
};

extern "C" char function_333bac(char* object, void*, value_slot* out) {
    out->pointer = *reinterpret_cast<void**>(object + 0x9b0);
    out->kind = 4;
    return 1;
}
