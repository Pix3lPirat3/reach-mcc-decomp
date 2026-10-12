struct object_a {
    unsigned char reserved0[0xc8];
    unsigned long long field_c8;
};
extern "C" unsigned long long function_8b2bc0(object_a* object) {
    return object->field_c8;
}
