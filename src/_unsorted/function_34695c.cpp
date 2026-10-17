struct Source {
    char reserved_0[0x160];
    int field_160;
};

struct Output {
    int kind;
    int reserved_4;
    int value;
};

extern "C" char function_34695c(const Source* source, long long, Output* output)
{
    int value = source->field_160;
    output->kind = 1;
    output->value = value;
    return 1;
}
