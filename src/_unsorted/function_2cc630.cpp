struct object_a {
    unsigned char reserved0[0x10];
    unsigned long long field_10;
};
extern "C" unsigned long long function_2cc630(object_a* object) {
    return object->field_10;
}
