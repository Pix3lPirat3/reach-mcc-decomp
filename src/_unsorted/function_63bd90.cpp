struct object_a {
    unsigned char reserved0[0x3c];
    unsigned int field_3c;
};
extern "C" unsigned int function_63bd90(object_a* object) {
    object->field_3c &= 0xffffff6fu;
    object->field_3c |= 0x40;
    return 0;
}
