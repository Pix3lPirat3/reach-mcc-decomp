struct Source {
    char reserved_0[0x70];
    unsigned int field_70;
};

extern "C" unsigned char function_34c62c(void* context, int direction, unsigned char flag);

extern "C" unsigned char function_34c604(Source* source)
{
    return function_34c62c(source, -1, ((source->field_70 >> 13) & 1));
}
