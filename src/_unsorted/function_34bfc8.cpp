struct Source {
    char reserved_0[0xa0];
    void* field_a0;
};

struct Output {
    int kind;
    int reserved_4;
    void* value;
};

extern "C" char function_34bfc8(const Source* source, long long, Output* output)
{
    output->value = source->field_a0;
    output->kind = 3;
    return 1;
}
