struct object_a {
    unsigned char reserved0[0x28];
    unsigned int field_28;
};
extern "C" unsigned int function_7f0c10(object_a* object) {
    return object->field_28;
}
