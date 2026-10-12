struct object_a {
    unsigned char reserved0[0x2a30];
    unsigned int field_2a30;
};
extern "C" unsigned int function_3bade8(object_a* object) {
    return object->field_2a30;
}
