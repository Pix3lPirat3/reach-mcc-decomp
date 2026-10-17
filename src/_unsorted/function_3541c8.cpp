struct Out {
    int kind;
    int reserved4;
    void* value;
};

extern "C" void* function_38b7a4();

extern "C" char function_3541c8(void*, void*, Out* out)
{
    out->value = function_38b7a4();
    out->kind = 3;
    return 1;
}
