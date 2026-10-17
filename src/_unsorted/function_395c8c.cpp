struct object_a {
    unsigned char reserved0[0x1738];
    unsigned int field_1738;
};
extern "C" unsigned int function_395c8c(object_a* object) {
    return object->field_1738;
}
