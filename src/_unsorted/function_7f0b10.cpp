struct object_a {
    unsigned char reserved0[0x24];
    unsigned int field_24;
};
extern "C" unsigned int function_7f0b10(object_a* object) {
    return object->field_24;
}
