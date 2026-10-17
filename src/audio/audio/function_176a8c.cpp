struct object_a {
    unsigned char reserved0[0x90];
    unsigned int field_90;
};
extern "C" void function_176a8c(object_a* object) {
    object->field_90 = 0;
}
