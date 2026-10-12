struct Source {
    char reserved0[0x70];
    int mode;
};
struct Out {
    char reserved_0[8];
    int value;
};

extern "C" void function_38be54(void* target);

extern "C" char function_356ebc(Source* source, void*, Out* out)
{
    int value = out->value;
    if (source->mode == value)
        return 1;
    source->mode = value;
    function_38be54(source);
    return 1;
}
