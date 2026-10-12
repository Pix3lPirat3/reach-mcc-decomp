struct object_a {
    unsigned char reserved0[0x58];
    unsigned int field_58;
};
extern "C" void EVP_CIPHER_CTX_set_num_79ebd0(object_a* object, unsigned int second) {
    object->field_58 = second;
}
