struct object_a {
    unsigned char reserved0[0x28];
    unsigned int field_28;
};
extern "C" unsigned int BIO_test_flags_7c2870(object_a* object, unsigned int second) {
    return object->field_28 & second;
}
