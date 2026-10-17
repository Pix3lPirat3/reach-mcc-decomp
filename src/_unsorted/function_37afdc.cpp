struct object_a {
    unsigned char reserved0[0x114];
    unsigned int field_114;
};
extern "C" unsigned int function_37afdc(object_a* object) {
    return object->field_114;
}
