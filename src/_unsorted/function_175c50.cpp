struct object_a {
    unsigned char reserved0[8];
    unsigned int field_8;
};
extern "C" unsigned int function_175c50(object_a* object) {
    return object->field_8;
}
