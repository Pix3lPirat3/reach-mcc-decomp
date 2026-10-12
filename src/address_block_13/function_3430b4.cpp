struct Source {
    char reserved_0[0x2b0];
    int field_2b0;
};

struct Output {
    int kind;
    int reserved_4;
    int value;
};

extern "C" char function_3430b4(const Source* source, long long, Output* output)
{
    int value = source->field_2b0;
    output->kind = 1;
    output->value = value;
    return 1;
}
