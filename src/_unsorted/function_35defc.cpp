struct Source {
    char reserved0[0x118];
    void* field;
};
struct Out {
    int kind;
    int reserved4;
    void* value;
};

extern "C" char function_35defc(Source* source, void*, Out* out)
{
    out->value = source->field;
    out->kind = 4;
    return 1;
}
