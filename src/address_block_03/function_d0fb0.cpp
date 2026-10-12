struct object_a {
    unsigned char reserved0[8];
    unsigned int field_8;
    unsigned int field_c;
};
extern "C" object_a* function_d0fb0(object_a* object) {
    object->field_c = 0x7f;
    object->field_8 = 0x7f;
    return object;
}
