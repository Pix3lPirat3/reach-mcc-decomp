struct Source {
    char reserved0[0xBF];
    char flag;
};
struct Out {
    int kind;
    int reserved4;
    char value;
};

extern "C" char function_352814(Source* source, void*, Out* out)
{
    char flag = source->flag;
    out->kind = 0;
    out->value = flag;
    return 1;
}
