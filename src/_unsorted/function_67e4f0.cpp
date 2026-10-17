struct object_a {
    unsigned char reserved0[0x38];
    unsigned int field_38;
};
extern "C" unsigned int function_67e4f0(object_a* object) {
    return object->field_38;
}
