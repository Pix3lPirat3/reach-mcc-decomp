struct value_slot {
    int kind;
    int reserved4;
    int number;
};

extern "C" char function_333368(char*, void*, value_slot* out) {
    out->kind = 6;
    out->number = 0x38049d;
    return 1;
}
