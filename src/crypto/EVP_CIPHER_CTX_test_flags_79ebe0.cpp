struct object_a {
    unsigned char reserved0[0x6c];
    unsigned int field_6c;
};
extern "C" unsigned int EVP_CIPHER_CTX_test_flags_79ebe0(object_a* object, unsigned int second) {
    return object->field_6c & second;
}
