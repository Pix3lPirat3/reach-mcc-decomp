struct source_object {
    unsigned char reserved0[0x140];
    long long pointer;
};

struct result_slot {
    int kind;
    int reserved4;
    bool value;
};

extern "C" char function_38a514(source_object* source, void*, result_slot* result) {
    bool present = source->pointer != 0;
    result->kind = 0;
    result->value = present;
    return 1;
}
