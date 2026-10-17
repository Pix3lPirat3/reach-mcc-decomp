struct inner_object {
    unsigned char reserved0[0x70];
    int value;
};

struct source_object {
    unsigned char reserved0[0xB0];
    inner_object* inner;
};

struct result_slot {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_38631c(source_object* source, void*, result_slot* result) {
    inner_object* inner = source->inner;
    int value = 0;
    if (inner != 0)
        value = inner->value;
    result->value = value;
    result->kind = 6;
    return 1;
}
