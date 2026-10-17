struct source_object {
    unsigned char reserved0[0x15C];
    int value;
};

struct result_slot {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_386848(source_object* source, void*, result_slot* result) {
    result->value = source->value;
    result->kind = 6;
    return 1;
}
