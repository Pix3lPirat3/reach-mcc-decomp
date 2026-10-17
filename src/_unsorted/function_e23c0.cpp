struct object_a {
    unsigned char reserved0[4];
    unsigned int field_4;
};
extern "C" unsigned int function_e23c0(object_a* object) {
    return object->field_4;
}
