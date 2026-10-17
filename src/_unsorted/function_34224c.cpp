struct Source {
    char reserved_0[0xbc];
    char field_bc;
};

struct Output {
    int kind;
    int reserved_4;
    char value;
};

extern "C" char function_34224c(const Source* source, long long, Output* output)
{
    char value = source->field_bc;
    output->kind = 0;
    output->value = value;
    return 1;
}
