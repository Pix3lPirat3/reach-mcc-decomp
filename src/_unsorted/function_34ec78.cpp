struct Source {
    char reserved_0[0x70];
    unsigned int field_70;
};

struct Output {
    int kind;
    int reserved_4;
    char value;
};

extern "C" char function_34ec78(const Source* source, long long, Output* output)
{
    unsigned int flags = source->field_70;
    output->kind = 0;
    output->value = static_cast<char>((flags >> 19) & 1);
    return 1;
}
