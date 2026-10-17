struct Source {
    char reserved_0[0x78];
    int field_78;
    char reserved_7c[0x6edcc];
    int field_6ee48;
    char reserved_6ee4c[0x4];
    int field_6ee50;
    char reserved_6ee54[0x4];
    int field_6ee58;
};

extern "C" int function_33e648(const Source* source)
{
    if (source->field_78 != 2)
        return source->field_6ee50;
    if (source->field_6ee58 != 2)
        return source->field_6ee50;
    return source->field_6ee48;
}
