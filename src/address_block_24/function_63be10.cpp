struct object_a {
    unsigned char reserved0[0x48];
    unsigned long long field_48;
};
extern "C" unsigned int function_63be10(object_a* object, unsigned long long second) {
    object->field_48 = second;
    return 0;
}
