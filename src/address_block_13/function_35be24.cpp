struct Source {
    char reserved0[0x370];
    int mode;
};
struct Out {
    int kind;
    int reserved4;
    unsigned char value;
};

extern "C" char function_35be24(Source* source, void*, Out* out)
{
    unsigned char matches = source->mode != 2;
    out->kind = 0;
    out->value = matches;
    return 1;
}
