struct Source {
    char reserved_0[0x70];
    char field_70;
};

struct Output {
    int kind;
    int reserved_4;
    bool value;
};

extern "C" char function_3415cc(const Source* source, long long, Output* output)
{
    char mode = source->field_70;
    output->kind = 0;
    output->value = mode == 4;
    return 1;
}
