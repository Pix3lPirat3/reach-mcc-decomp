struct Out {
    char reserved_0[8];
    char value;
};

extern "C" void function_38b944(void* target, char value);

extern "C" char function_356ad8(void* source, void*, Out* out)
{
    function_38b944(source, out->value);
    return 1;
}
