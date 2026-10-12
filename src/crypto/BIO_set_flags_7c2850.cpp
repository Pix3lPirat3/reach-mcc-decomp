struct object_a {
    unsigned char reserved0[0x28];
    unsigned int field_28;
};
extern "C" void BIO_set_flags_7c2850(object_a* object, unsigned int second) {
    object->field_28 |= second;
}
