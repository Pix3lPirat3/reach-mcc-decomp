struct object_a {
    unsigned char reserved0[0xc0];
    unsigned int field_c0;
};
extern "C" unsigned int function_3ef054(object_a* object) {
    object->field_c0 = 0;
    return 0x80004005u;
}
