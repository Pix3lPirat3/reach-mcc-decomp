struct Source {
    char reserved0[0xBE];
    char flag;
};
struct Out {
    int kind;
    int reserved4;
    char value;
};

extern "C" char function_352800(Source* source, void*, Out* out)
{
    char flag = source->flag;
    out->kind = 0;
    out->value = flag;
    return 1;
}
