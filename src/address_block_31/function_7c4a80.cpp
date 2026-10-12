struct object_a {
    unsigned char reserved0[0x30];
    unsigned int field_30;
};
extern "C" unsigned int function_7c4a80(object_a* object) {
    return object->field_30;
}
