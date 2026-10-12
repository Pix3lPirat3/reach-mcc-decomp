struct Source {
    char reserved_0[0x74];
    unsigned char field_74;
    char reserved_75[0x4];
    unsigned char field_79;
};

struct Output {
    int kind;
    int reserved_4;
    bool value;
};

extern "C" char function_3480cc(const Source* source, long long, Output* output)
{
    bool value = source->field_79 != 0 && source->field_74 == 2;
    output->kind = 0;
    output->value = value;
    return 1;
}
