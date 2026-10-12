struct Source {
    char reserved_0[0xbd];
    char field_bd;
};

struct Output {
    int kind;
    int reserved_4;
    char value;
};

extern "C" char function_342260(const Source* source, long long, Output* output)
{
    char value = source->field_bd;
    output->kind = 0;
    output->value = value;
    return 1;
}
