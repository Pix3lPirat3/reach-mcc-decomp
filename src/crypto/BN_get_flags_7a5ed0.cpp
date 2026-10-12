struct object_a {
    unsigned char reserved0[0x14];
    unsigned int field_14;
};
extern "C" unsigned int BN_get_flags_7a5ed0(object_a* object, unsigned int second) {
    return object->field_14 & second;
}
