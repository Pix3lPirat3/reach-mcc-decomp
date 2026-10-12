struct Out {
    int kind;
    int reserved4;
    char* value;
};

extern "C" char function_35683c(char* source, void*, Out* out)
{
    out->kind = 3;
    out->value = source + 0xC34;
    return 1;
}
