struct Source {
    char reserved_0[0x78];
    int field_78;
    char reserved_7c[0x70cbc];
    int field_70d38;
    char reserved_70d3c[0x4];
    int field_70d40;
    char reserved_70d44[0x4];
    int field_70d48;
};

extern "C" int function_33be8c(const Source* source)
{
    if (source->field_78 != 3)
        return source->field_70d40;
    if (source->field_70d48 != 2)
        return source->field_70d40;
    return source->field_70d38;
}
