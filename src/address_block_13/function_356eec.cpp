struct Out {
    int kind;
    int reserved4;
    int value;
};

extern "C" int function_38bb88(void* target);

extern "C" char function_356eec(void* source, void*, Out* out)
{
    out->value = function_38bb88(source);
    out->kind = 1;
    return 1;
}
