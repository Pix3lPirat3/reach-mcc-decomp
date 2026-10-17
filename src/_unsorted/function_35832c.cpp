struct Source {
    char reserved0[0x80];
    char enabled;
    char reserved81[3];
    int value;
};
struct Out {
    char reserved_0[8];
    int value;
};

extern "C" char function_35832c(Source* source, void*, Out* out)
{
    int value = out->value;
    source->enabled = 1;
    source->value = value;
    return 1;
}
