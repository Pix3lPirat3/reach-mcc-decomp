struct Source {
    char reserved_0[0x88];
    void* field_88;
};

struct Output {
    int kind;
    int reserved_4;
    void* value;
};

extern "C" char function_34812c(const Source* source, long long, Output* output)
{
    output->value = source->field_88;
    output->kind = 4;
    return 1;
}
