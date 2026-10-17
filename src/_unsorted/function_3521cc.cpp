struct Source {
    char reserved0[0x2FD0];
    int field;
};
struct Out {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_3521cc(Source* source, void*, Out* out)
{
    int value = out->value;
    source->field = value < 0 ? 0 : value;
    return 1;
}
