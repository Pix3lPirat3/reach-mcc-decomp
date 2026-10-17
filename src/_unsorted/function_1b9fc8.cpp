struct object_a {
    unsigned char reserved0[0x28];
    unsigned long long field_28;
};
extern "C" void function_1b9fc8(object_a* object) {
    object->field_28 = 0;
}
