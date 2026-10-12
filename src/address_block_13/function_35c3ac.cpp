struct Source {
    char reserved0[0xA4];
    char field_a4[1];
};
struct Out {
    char reserved_0[8];
    void* value;
};

extern "C" void* function_35c3c(void* destination, void* text, unsigned long long length);

extern "C" char function_35c3ac(Source* source, void*, Out* out)
{
    function_35c3c(source->field_a4, out->value, 0x100);
    return 1;
}
