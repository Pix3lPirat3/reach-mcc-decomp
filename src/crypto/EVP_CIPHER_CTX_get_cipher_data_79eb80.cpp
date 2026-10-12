struct object_a {
    unsigned char reserved0[0x70];
    unsigned long long field_70;
};
extern "C" unsigned long long EVP_CIPHER_CTX_get_cipher_data_79eb80(object_a* object) {
    return object->field_70;
}
