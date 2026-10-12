struct object_a {
    unsigned char reserved0[0xc8];
    unsigned long long field_c8;
};
extern "C" void function_8b2bd0(object_a* object, unsigned long long second) {
    object->field_c8 = second;
}
