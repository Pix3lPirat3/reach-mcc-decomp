struct object_a {
    unsigned char reserved0[0x40];
    unsigned int field_40;
};
extern "C" unsigned int function_58ff60(object_a* object, unsigned int second) {
    object->field_40 = second;
    return 0;
}
