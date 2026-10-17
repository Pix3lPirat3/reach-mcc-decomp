struct Source {
    char reserved_0[0x124];
    int field_124;
};

struct Output {
    int kind;
    int reserved_4;
    int value;
};

extern "C" char function_3415e0(const Source* source, long long, Output* output)
{
    int value = source->field_124;
    output->kind = 1;
    output->value = value;
    return 1;
}
