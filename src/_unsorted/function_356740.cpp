struct Source {
    char reserved0[0x1240];
    int field;
};
struct Out {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_356740(Source* source, void*, Out* out)
{
    out->value = source->field;
    out->kind = 6;
    return 1;
}
