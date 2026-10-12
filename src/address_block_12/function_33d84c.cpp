struct Source {
    char reserved_0[0x70];
    unsigned int field_70;
    char reserved_74[0x41b4];
    unsigned int field_4228;
};

struct Output {
    int kind;
    int reserved_4;
    bool value;
};

extern "C" char function_33d84c(const Source* source, long long, Output* output)
{
    bool value = source->field_70 <= 1 || (source->field_70 == 2 && source->field_4228 <= 1);
    output->kind = 0;
    output->value = value;
    return 1;
}
