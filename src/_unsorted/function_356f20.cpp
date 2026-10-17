struct Source {
    char reserved0[0x1820];
    int field;
};
struct Out {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_356f20(Source* source, void*, Out* out)
{
    int field = source->field;
    out->kind = 1;
    out->value = field;
    return 1;
}
