struct Out {
    int kind;
    int reserved4;
    char* value;
};

extern "C" char function_356854(char* source, void*, Out* out)
{
    out->kind = 3;
    out->value = source + 0xE34;
    return 1;
}
