struct object_a {
    unsigned char reserved0[0xa0];
    unsigned int field_a0;
};
extern "C" unsigned int function_3741c0(object_a* object) {
    return object->field_a0;
}
