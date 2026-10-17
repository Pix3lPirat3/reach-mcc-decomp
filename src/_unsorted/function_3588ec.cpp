struct Source {
    char reserved0[0x81];
    char enabled;
    char reserved82[6];
    int value;
};
struct Out {
    char reserved_0[8];
    int value;
};

extern "C" char function_3588ec(Source* source, void*, Out* out)
{
    int value = out->value;
    source->enabled = 1;
    source->value = value;
    return 1;
}
