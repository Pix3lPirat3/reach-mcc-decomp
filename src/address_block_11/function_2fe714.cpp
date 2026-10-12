struct object_a {
    unsigned char reserved0[0x234];
    int field_234;
};
extern "C" bool function_2fe714(object_a* object) {
    return object->field_234 > 0;
}
