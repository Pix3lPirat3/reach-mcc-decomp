struct object_a_field_0 {
    unsigned char reserved0[4];
    unsigned int field_4;
};

struct object_a {
    object_a_field_0* field_0;
};
extern "C" unsigned int EVP_CIPHER_CTX_block_size_79eb50(object_a* object) {
    return object->field_0->field_4;
}
