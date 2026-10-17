struct source {
    char reserved0[0x14c];
    int field_14c;
    char reserved150[0xf0];
    int field_240;
};

extern "C" int function_3068b4(source* object, int offset) {
    int base = object->field_240;
    if (base != -1)
        return base + offset;
    return object->field_14c + offset;
}
