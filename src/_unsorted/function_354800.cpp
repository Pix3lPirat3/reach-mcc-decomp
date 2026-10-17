struct Source {
    char reserved0[0x70];
    int count;
};
struct Out {
    int kind;
    int reserved4;
    char value;
};

extern "C" char function_354800(Source* source, void*, Out* out)
{
    bool positive = source->count > 0;
    out->kind = 0;
    out->value = positive;
    return 1;
}
