struct object_a {
    unsigned char reserved0[0xb0];
    unsigned int field_b0;
};
extern "C" unsigned int function_2d0c44(object_a* object) {
    return object->field_b0;
}
