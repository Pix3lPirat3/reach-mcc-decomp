struct Source {
    char reserved0[0x1A50];
    void* field;
};
struct Out {
    int kind;
    int reserved4;
    void* value;
};

extern "C" char function_356698(Source* source, void*, Out* out)
{
    out->value = source->field;
    out->kind = 4;
    return 1;
}
