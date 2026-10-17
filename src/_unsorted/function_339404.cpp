struct value_slot {
    int kind;
    int reserved4;
    void* pointer;
};

extern "C" char function_339404(char* object, void*, value_slot* out) {
    int mode = *reinterpret_cast<int*>(object + 0x930);
    out->kind = 3;
    out->pointer = mode != 1 ? nullptr : object + 0xa38;
    return 1;
}
