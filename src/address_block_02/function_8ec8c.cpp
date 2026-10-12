struct object_a {
    unsigned char reserved0[0x114c2f];
    bool field_114c2f;
};
extern "C" bool function_8ec8c(object_a* object) {
    return object->field_114c2f;
}
