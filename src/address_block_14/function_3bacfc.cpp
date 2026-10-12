struct object_a {
    unsigned char reserved0[0x700];
    unsigned int field_700;
};
extern "C" unsigned int function_3bacfc(object_a* object) {
    return object->field_700;
}
