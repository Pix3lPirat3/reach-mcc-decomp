struct value_slot {
    int kind;
    int reserved4;
    void* pointer;
};

extern "C" char function_338d78(char* object, void*, value_slot* out) {
    out->kind = 3;
    out->pointer = object + 0x874;
    return 1;
}
