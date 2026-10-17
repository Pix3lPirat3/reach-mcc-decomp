struct Source {
    char reserved_0[0x74];
    unsigned int field_74;
    char reserved_78[0x39e0];
    unsigned int field_3a58;
};

struct Output {
    int kind;
    int reserved_4;
    bool value;
};

extern "C" char function_340684(const Source* source, long long, Output* output)
{
    bool value = source->field_74 <= 1 || (source->field_74 == 2 && source->field_3a58 <= 1);
    output->kind = 0;
    output->value = value;
    return 1;
}
