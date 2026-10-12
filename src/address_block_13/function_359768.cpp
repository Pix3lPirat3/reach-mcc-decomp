struct Source {
    char reserved0[0x74];
    int field_74;
    char reserved78[0x72E50];
    int field_72ec8;
    char reserved72ECC[4];
    int field_72ed0;
    char reserved72ED4[4];
    int field_72ed8;
};

extern "C" int function_359768(Source* source)
{
    if (source->field_74 != 1)
        return source->field_72ed0;
    if (source->field_72ed8 != 2)
        return source->field_72ed0;
    return source->field_72ec8;
}
