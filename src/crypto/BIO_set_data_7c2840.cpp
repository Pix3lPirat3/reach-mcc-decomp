struct object_a {
    unsigned char reserved0[0x38];
    unsigned long long field_38;
};
extern "C" void BIO_set_data_7c2840(object_a* object, unsigned long long second) {
    object->field_38 = second;
}
