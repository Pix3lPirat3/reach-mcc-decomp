struct object_a {
    unsigned char reserved0[0x100];
    unsigned long long field_100;
};
extern "C" unsigned long long function_8b36a0(object_a* object) {
    return object->field_100;
}
