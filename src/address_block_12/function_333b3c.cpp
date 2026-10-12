struct value_slot {
    int kind;
    int reserved4;
    void* pointer;
};

extern "C" char function_333b3c(char* object, void*, value_slot* out) {
    out->pointer = *reinterpret_cast<void**>(object + 0x998);
    out->kind = 4;
    return 1;
}
