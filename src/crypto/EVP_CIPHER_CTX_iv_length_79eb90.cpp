struct object_a_field_0 {
    unsigned char reserved0[0xc];
    unsigned int field_c;
};

struct object_a {
    object_a_field_0* field_0;
};
extern "C" unsigned int EVP_CIPHER_CTX_iv_length_79eb90(object_a* object) {
    return object->field_0->field_c;
}
