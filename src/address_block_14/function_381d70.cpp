struct object_a {
    unsigned char reserved0[0x7c];
    unsigned int field_7c;
};
extern "C" unsigned int function_381d70(object_a* object) {
    return object->field_7c;
}
