struct Source {
    char reserved_0[0xbd];
    unsigned char field_bd;
};

struct Output {
    int kind;
    int reserved_4;
    bool value;
};

extern "C" char function_342234(const Source* source, long long, Output* output)
{
    bool value = source->field_bd == 0;
    output->kind = 0;
    output->value = value;
    return 1;
}
