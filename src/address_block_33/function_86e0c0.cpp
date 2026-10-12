struct object_a {
    unsigned char reserved0[0x1520];
    unsigned long long field_1520;
};
extern "C" unsigned long long function_86e0c0(object_a* object) {
    return object->field_1520;
}
