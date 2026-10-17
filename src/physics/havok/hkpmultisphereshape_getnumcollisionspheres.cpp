struct object_a {
    unsigned char reserved0[0x20];
    unsigned int field_20;
};
extern "C" unsigned int function_885e60(object_a* object) {
    return object->field_20;
}
