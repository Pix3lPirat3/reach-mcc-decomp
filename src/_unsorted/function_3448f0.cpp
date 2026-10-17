struct Source {
    char reserved_0[0xfac];
    int field_fac;
};

struct Output {
    int kind;
    int reserved_4;
    int value;
};

extern "C" char function_3448f0(const Source* source, long long, Output* output)
{
    int value = source->field_fac;
    output->kind = 1;
    output->value = value;
    return 1;
}
