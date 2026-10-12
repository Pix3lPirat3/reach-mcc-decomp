struct Out {
    int kind;
    int reserved4;
    int value;
};

extern "C" int function_38ba30(void* target);

extern "C" char function_356aec(void* source, void*, Out* out)
{
    out->value = function_38ba30(source);
    out->kind = 1;
    return 1;
}
