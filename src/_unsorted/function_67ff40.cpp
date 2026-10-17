struct object_a {
    unsigned char reserved0[0x20];
    unsigned int field_20;
    unsigned char reserved24[4];
    unsigned long long field_28;
};
extern "C" void function_67ff40(object_a* object, unsigned long long second) {
    object->field_20 += 1;
    object->field_28 = second;
}
