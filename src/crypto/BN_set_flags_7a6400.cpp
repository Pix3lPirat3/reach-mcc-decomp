struct object_a {
    unsigned char reserved0[0x14];
    unsigned int field_14;
};
extern "C" void BN_set_flags_7a6400(object_a* object, unsigned int second) {
    object->field_14 |= second;
}
