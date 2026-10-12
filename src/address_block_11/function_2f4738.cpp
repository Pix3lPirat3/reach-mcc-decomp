struct object_a {
    unsigned char reserved0[0x110];
    unsigned int field_110;
};
extern "C" unsigned int function_2f4738(object_a* object) {
    return object->field_110;
}
