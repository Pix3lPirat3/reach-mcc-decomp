struct object_a {
    unsigned char reserved0[0x28];
    unsigned long long field_28;
};
extern "C" void function_79f280(object_a* object, unsigned long long second) {
    object->field_28 = second;
}
