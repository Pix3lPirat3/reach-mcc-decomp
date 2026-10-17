struct Source {
    char reserved_0[0xb4];
    int field_b4;
};

struct Output {
    int kind;
    int reserved_4;
    int value;
};

extern "C" char function_3421d8(const Source* source, long long, Output* output)
{
    int value = source->field_b4;
    output->kind = 1;
    output->value = value;
    return 1;
}
