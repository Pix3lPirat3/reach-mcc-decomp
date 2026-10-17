struct Source {
    char reserved_0[0x70];
    int field_70;
};

struct Output {
    int kind;
    int reserved_4;
    bool value;
};

extern "C" char function_342538(const Source* source, long long, Output* output)
{
    bool value = source->field_70 != 0;
    output->kind = 0;
    output->value = value;
    return 1;
}
