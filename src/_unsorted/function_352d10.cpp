struct Out {
    char reserved_0[8];
    unsigned short value;
};

extern "C" void function_352910(void* target, unsigned short value);

extern "C" char function_352d10(void* source, void*, Out* out)
{
    function_352910(source, out->value);
    return 1;
}
