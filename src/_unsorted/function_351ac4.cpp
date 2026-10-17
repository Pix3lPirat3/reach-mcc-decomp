struct Source {
    char reserved0[0x152];
    char flags;
};
struct Out {
    int kind;
    int reserved4;
    char value;
};

extern "C" char function_351ac4(Source* source, void*, Out* out)
{
    char flags = source->flags;
    out->kind = 0;
    out->value = flags & 1;
    return 1;
}
