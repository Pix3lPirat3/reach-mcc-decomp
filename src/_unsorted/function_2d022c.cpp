struct object_a {
    unsigned char reserved0[0x40];
    unsigned int field_40;
};
extern "C" unsigned int function_2d022c(object_a* object) {
    return object->field_40;
}
