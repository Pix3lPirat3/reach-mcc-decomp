struct object_a {
    unsigned char reserved0[0x28];
    unsigned int field_28;
};
extern "C" void function_7f0f70(object_a* object, unsigned int second) {
    object->field_28 = second;
}
