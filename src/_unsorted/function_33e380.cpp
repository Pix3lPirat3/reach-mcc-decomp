struct Source {
    char reserved_0[0x248];
    void* field_248;
};

struct Output {
    int kind;
    int reserved_4;
    void* value;
};

extern "C" char function_33e380(const Source* source, long long, Output* output)
{
    output->value = source->field_248;
    output->kind = 4;
    return 1;
}
