struct object_a {
    unsigned char reserved0[0x68];
    unsigned int field_68;
};
extern "C" unsigned int EVP_CIPHER_CTX_key_length_79eba0(object_a* object) {
    return object->field_68;
}
