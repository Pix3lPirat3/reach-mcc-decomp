struct object_a {
    unsigned char reserved0[0x58];
    unsigned int field_58;
};
extern "C" unsigned int EVP_CIPHER_CTX_num_79ebb0(object_a* object) {
    return object->field_58;
}
