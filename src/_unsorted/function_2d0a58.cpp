struct object_a {
    unsigned char reserved0[0x1c];
    bool field_1c;
};
extern "C" bool function_2d0a58(object_a* object) {
    return object->field_1c;
}
