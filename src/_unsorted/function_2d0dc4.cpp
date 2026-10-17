struct object_a {
    unsigned char reserved0[0x90];
    unsigned int field_90;
};
extern "C" unsigned int function_2d0dc4(object_a* object) {
    return object->field_90;
}
