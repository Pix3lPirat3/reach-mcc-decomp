struct Source {
    char reserved0[0xC4];
    int mode;
};
struct Out {
    int kind;
    int reserved4;
    char value;
};

extern "C" char function_3527d0(Source* source, void*, Out* out)
{
    bool matches = source->mode == 3;
    out->kind = 0;
    out->value = matches;
    return 1;
}
