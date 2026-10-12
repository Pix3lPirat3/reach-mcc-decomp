struct object_a {
    unsigned char reserved0[0x3d8];
    bool field_3d8;
};
extern "C" bool function_69508(object_a* object) {
    return object->field_3d8;
}
