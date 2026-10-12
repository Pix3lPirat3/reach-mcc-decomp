struct source_object {
    unsigned char reserved0[0x300];
    long long value;
};

struct result_slot {
    int kind;
    int reserved4;
    long long value;
};

extern "C" char function_37dc2c(source_object* source, void*, result_slot* result) {
    result->value = source->value;
    result->kind = 4;
    return 1;
}
