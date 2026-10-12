struct object_a {
    unsigned char reserved0[0x3c];
    unsigned int field_3c;
};
extern "C" unsigned int function_7c4a90(object_a* object) {
    return object->field_3c;
}
