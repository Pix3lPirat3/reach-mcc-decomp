struct Source {
    char reserved_0[0x74];
    char field_74;
};

struct Output {
    int kind;
    int reserved_4;
    bool value;
};

extern "C" char function_348078(const Source* source, long long, Output* output)
{
    char mode = source->field_74;
    output->kind = 0;
    output->value = mode == 3;
    return 1;
}
