struct object_a {
    unsigned char reserved0[0x38];
    unsigned long long field_38;
};
extern "C" unsigned long long BIO_get_data_7c1f60(object_a* object) {
    return object->field_38;
}
