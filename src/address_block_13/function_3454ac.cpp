struct Source {
    char reserved_0[0x5680];
    int field_5680;
};

struct Output {
    int kind;
    int reserved_4;
    int value;
};

extern "C" char function_3454ac(const Source* source, long long, Output* output)
{
    int value = source->field_5680;
    output->kind = 1;
    output->value = value;
    return 1;
}
