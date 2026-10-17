struct object_a {
    unsigned char reserved0[0x160];
    unsigned long long field_160;
};
extern "C" unsigned int function_63c2a0(object_a* object, unsigned long long second) {
    object->field_160 = second;
    return 0;
}
