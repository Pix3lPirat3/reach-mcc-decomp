struct Source {
    char reserved_0[0x430];
    int field_430;
};

struct Output {
    int kind;
    int reserved_4;
    int value;
};

extern "C" char function_348938(const Source* source, long long, Output* output)
{
    int value = source->field_430;
    output->kind = 1;
    output->value = value;
    return 1;
}
