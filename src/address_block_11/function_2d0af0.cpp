struct object_a {
    unsigned char reserved0[0x14];
    unsigned int field_14;
};
extern "C" unsigned int function_2d0af0(object_a* object) {
    return object->field_14;
}
