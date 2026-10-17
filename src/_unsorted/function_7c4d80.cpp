struct object_a {
    unsigned char reserved0[0x30];
    unsigned int field_30;
};
extern "C" void function_7c4d80(object_a* object, unsigned int second) {
    object->field_30 = second;
}
