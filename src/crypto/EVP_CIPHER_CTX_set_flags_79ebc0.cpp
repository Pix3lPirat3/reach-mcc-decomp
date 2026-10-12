struct object_a {
    unsigned char reserved0[0x6c];
    unsigned int field_6c;
};
extern "C" void EVP_CIPHER_CTX_set_flags_79ebc0(object_a* object, unsigned int second) {
    object->field_6c |= second;
}
