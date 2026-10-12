struct Out {
    int kind;
    int reserved4;
    char* value;
};

extern "C" char function_3573c8(char* source, void*, Out* out)
{
    out->kind = 12;
    out->value = source + 0x74;
    return 1;
}
