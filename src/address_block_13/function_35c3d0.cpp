struct Out {
    int kind;
    int reserved4;
    char* value;
};

extern "C" char function_35c3d0(char* source, void*, Out* out)
{
    out->kind = 3;
    out->value = source + 0x2A4;
    return 1;
}
