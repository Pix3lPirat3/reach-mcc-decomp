struct object_a {
    unsigned char reserved0[0x10];
    unsigned int field_10;
};
extern "C" void function_79f270(object_a* object, unsigned int second) {
    object->field_10 |= second;
}
