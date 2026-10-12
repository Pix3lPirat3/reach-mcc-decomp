struct object_a {
    unsigned char reserved0[0x3c];
    unsigned int field_3c;
};
extern "C" void function_7c4d90(object_a* object, unsigned int second) {
    object->field_3c |= second;
}
