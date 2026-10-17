struct value_slot {
    int kind;
    int reserved4;
    int number;
};

extern "C" char function_337240(char* object, void*, value_slot* out) {
    out->number = *reinterpret_cast<int*>(object + 0x88);
    out->kind = 6;
    return 1;
}
