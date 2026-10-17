struct Source {
    char reserved0[0x150];
    unsigned int flags;
};
struct Out {
    int kind;
    int reserved4;
    char value;
};

extern "C" char function_351a8c(Source* source, void*, Out* out)
{
    unsigned int flags = source->flags;
    out->kind = 0;
    out->value = static_cast<char>((flags >> 15) & 1);
    return 1;
}
