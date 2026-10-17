struct Out {
    char reserved_0[8];
    int value;
};

extern "C" void function_38ba94(void* target, int value);

extern "C" char function_356b0c(void* source, void*, Out* out)
{
    function_38ba94(source, out->value);
    return 1;
}
