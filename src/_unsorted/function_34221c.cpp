struct Source {
    char reserved_0[0xbc];
    unsigned char field_bc;
};

struct Output {
    int kind;
    int reserved_4;
    bool value;
};

extern "C" char function_34221c(const Source* source, long long, Output* output)
{
    bool value = source->field_bc == 0;
    output->kind = 0;
    output->value = value;
    return 1;
}
