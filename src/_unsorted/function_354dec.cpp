struct Source {
    char reserved0[0x98];
    char flag;
};
struct Out {
    int kind;
    int reserved4;
    char value;
};

extern "C" char function_354dec(Source* source, void*, Out* out)
{
    char flag = source->flag;
    out->kind = 0;
    out->value = flag;
    return 1;
}
