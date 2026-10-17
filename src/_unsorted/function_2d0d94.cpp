struct object_a {
    unsigned char reserved0[0x208];
    unsigned int field_208;
};
extern "C" unsigned int function_2d0d94(object_a* object) {
    return object->field_208;
}
