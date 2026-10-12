struct value_slot {
    int kind;
    int reserved4;
    void* pointer;
};

extern "C" char function_3394d4(char* object, void*, value_slot* out) {
    out->kind = 3;
    out->pointer = object + 0x8b6;
    return 1;
}
