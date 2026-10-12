struct object_a {
    unsigned char reserved0[0x15b0];
    unsigned int field_15b0;
};
extern "C" unsigned int function_32c5f8(object_a* object) {
    return object->field_15b0;
}
