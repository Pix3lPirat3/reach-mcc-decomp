struct object_a {
    unsigned char reserved0[0x24];
    unsigned int field_24;
};
extern "C" void function_7f0da0(object_a* object, unsigned int second) {
    object->field_24 = second;
}
