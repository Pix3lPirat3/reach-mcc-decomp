struct object_a {
    unsigned char reserved0[0x232a0];
    unsigned int field_232a0[1];
};
extern "C" void function_238f44(object_a* object, unsigned int second, unsigned int third) {
    object->field_232a0[second] = third;
}
