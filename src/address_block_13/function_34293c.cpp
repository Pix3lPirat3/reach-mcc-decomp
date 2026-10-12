struct Source {
    char reserved_0[0x70];
    int field_70;
    char reserved_74[0xec];
    int field_160;
    char reserved_164[0xf0];
    char field_254;
    char reserved_255[0x2f];
    unsigned char field_284;
};

struct Output {
    int kind;
    int reserved_4;
    int value;
};

extern "C" char function_34293c(const Source* source, long long, Output* output)
{
    int value = 0;
    if (source->field_70 == 4 && (source->field_284 & 1) != 0) {
        value = source->field_160;
        if (source->field_254 != 0)
            ++value;
    }
    output->kind = 1;
    output->value = value;
    return 1;
}
