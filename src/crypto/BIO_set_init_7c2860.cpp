struct object_a {
    unsigned char reserved0[0x20];
    unsigned int field_20;
};
extern "C" void BIO_set_init_7c2860(object_a* object, unsigned int second) {
    object->field_20 = second;
}
