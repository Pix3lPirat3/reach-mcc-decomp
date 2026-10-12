struct object_a {
    unsigned char reserved0[0x50];
    unsigned int field_50;
};
extern "C" unsigned int function_2d02e0(object_a* object) {
    return object->field_50;
}
