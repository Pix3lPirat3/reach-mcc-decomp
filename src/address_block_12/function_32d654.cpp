struct object_a {
    unsigned char reserved0[0x1944];
    unsigned int field_1944;
};
extern "C" unsigned int function_32d654(object_a* object) {
    return object->field_1944;
}
