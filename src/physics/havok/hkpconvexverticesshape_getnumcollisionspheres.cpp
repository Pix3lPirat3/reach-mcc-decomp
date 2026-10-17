struct object_a {
    unsigned char reserved0[0x60];
    unsigned int field_60;
};
extern "C" unsigned int function_8832f0(object_a* object) {
    return object->field_60;
}
