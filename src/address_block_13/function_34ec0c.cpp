struct Source {
    char reserved_0[0x70];
    int field_70;
};

struct Output {
    int kind;
    int reserved_4;
    unsigned char value;
};

extern "C" char function_34c56c(Source* source);
extern "C" float function_34dae0(Source* source);

extern "C" char function_34ec0c(Source* source, long long, const Output* input)
{
    int flags = source->field_70;
    source->field_70 = input->value == 0 ? (flags & ~0x1000) : (flags | 0x1000);
    if (function_34c56c(source) != 0)
        return 1;
    function_34dae0(source);
    return 1;
}
