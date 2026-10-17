struct object_a {
    unsigned char reserved0[0x1820];
    unsigned int field_1820;
};
extern "C" unsigned int function_356f34(object_a* object) {
    return object->field_1820;
}
