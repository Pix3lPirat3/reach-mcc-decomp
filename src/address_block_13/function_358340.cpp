struct Out {
    int kind;
    int reserved4;
    int value;
};

extern "C" int function_357668(void* target);

extern "C" char function_358340(void* source, void*, Out* out)
{
    out->value = function_357668(source);
    out->kind = 1;
    return 1;
}
