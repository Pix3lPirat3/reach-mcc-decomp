struct object_a {
    unsigned char reserved0[0x10];
    unsigned int field_10;
};
extern "C" unsigned int function_321a0(object_a* object) {
    return object->field_10;
}
