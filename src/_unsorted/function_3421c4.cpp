struct Source {
    char reserved_0[0xb8];
    int field_b8;
};

struct Output {
    int kind;
    int reserved_4;
    int value;
};

extern "C" char function_3421c4(const Source* source, long long, Output* output)
{
    int value = source->field_b8;
    output->kind = 1;
    output->value = value;
    return 1;
}
