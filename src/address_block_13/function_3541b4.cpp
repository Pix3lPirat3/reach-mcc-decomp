struct Out {
    char reserved_0[8];
    int value;
};

extern "C" void function_38b728(void* target, int value);

extern "C" char function_3541b4(void* source, void*, Out* out)
{
    function_38b728(source, out->value);
    return 1;
}
