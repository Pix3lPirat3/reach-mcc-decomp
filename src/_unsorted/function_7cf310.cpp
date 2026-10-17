struct object_a {
    unsigned char reserved0[0x2c];
    unsigned int field_2c;
};
extern "C" void function_7cf310(object_a* object, unsigned int second) {
    object->field_2c = second;
}
