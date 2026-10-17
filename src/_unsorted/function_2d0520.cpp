struct object_a {
    unsigned char reserved0[0x10];
    bool field_10;
};
extern "C" bool function_2d0520(object_a* object) {
    return object->field_10;
}
