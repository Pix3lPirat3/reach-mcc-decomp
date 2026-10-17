struct object_a {
    unsigned char reserved0[0x2a1c0];
    unsigned int field_2a1c0;
};
extern "C" unsigned int function_32b294(object_a* object) {
    return object->field_2a1c0;
}
