struct Source {
    char reserved0[0x4A8];
    void* field;
};
struct Out {
    int kind;
    int reserved4;
    void* value;
};

extern "C" char function_35cbac(Source* source, void*, Out* out)
{
    out->value = source->field;
    out->kind = 4;
    return 1;
}
