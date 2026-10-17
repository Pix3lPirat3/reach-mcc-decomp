struct object_a {
    unsigned char reserved0[0x1f4];
    unsigned int field_1f4;
};
extern "C" unsigned int function_36b1dc(object_a* object) {
    return object->field_1f4;
}
