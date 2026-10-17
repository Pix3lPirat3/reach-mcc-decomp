struct object_a {
    unsigned char reserved0[0x12d0];
    unsigned int field_12d0;
};
extern "C" unsigned int function_32aba8(object_a* object) {
    return object->field_12d0;
}
