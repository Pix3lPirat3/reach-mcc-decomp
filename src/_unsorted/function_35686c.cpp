struct Out {
    int kind;
    int reserved4;
    char* value;
};

extern "C" char function_35686c(char* source, void*, Out* out)
{
    out->kind = 3;
    out->value = source + 0x1034;
    return 1;
}
