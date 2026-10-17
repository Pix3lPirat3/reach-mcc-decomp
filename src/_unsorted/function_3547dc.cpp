struct Source {
    char reserved0[0x52C];
    int field;
};
struct Out {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_3547dc(Source* source, void*, Out* out)
{
    int field = source->field;
    out->kind = 1;
    out->value = field;
    return 1;
}
