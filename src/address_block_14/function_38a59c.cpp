struct source_object {
    unsigned char reserved0[0x15C];
    int value;
};

struct result_slot {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_38a59c(source_object* source, void*, result_slot* result) {
    int value = source->value;
    result->kind = 1;
    result->value = value;
    return 1;
}
