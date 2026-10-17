struct Source {
    char reserved_0[0x438];
    int field_438;
};

struct Output {
    int kind;
    int reserved_4;
    int value;
};

extern "C" char function_348924(const Source* source, long long, Output* output)
{
    int value = source->field_438;
    output->kind = 1;
    output->value = value;
    return 1;
}
