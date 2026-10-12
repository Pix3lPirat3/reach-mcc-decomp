struct Source {
    char reserved0[0x2874];
    int field;
};
struct Out {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_3541a0(Source* source, void*, Out* out)
{
    int field = source->field;
    out->kind = 1;
    out->value = field;
    return 1;
}
