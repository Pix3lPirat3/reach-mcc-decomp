struct Source {
    char reserved_0[0x128];
    int field_128;
};

struct Output {
    int kind;
    int reserved_4;
    int value;
};

extern "C" char function_3415f4(const Source* source, long long, Output* output)
{
    int value = source->field_128;
    output->kind = 1;
    output->value = value;
    return 1;
}
