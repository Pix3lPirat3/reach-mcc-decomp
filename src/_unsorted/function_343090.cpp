struct Source {
    char reserved_0[0x2ac];
    int field_2ac;
};

struct Output {
    int kind;
    int reserved_4;
    int value;
};

extern "C" char function_343090(const Source* source, long long, Output* output)
{
    int value = source->field_2ac;
    output->kind = 1;
    output->value = value;
    return 1;
}
