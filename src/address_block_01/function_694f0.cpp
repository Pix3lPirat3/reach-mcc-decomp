struct object_a {
    unsigned char reserved0[0x88];
    unsigned long long field_88;
};
extern "C" unsigned long long function_694f0(object_a* object) {
    return object->field_88;
}
