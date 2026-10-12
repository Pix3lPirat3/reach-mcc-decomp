struct object_a {
    unsigned char reserved0[0xba];
    bool field_ba;
};
extern "C" bool function_dfea8(object_a* object) {
    return object->field_ba;
}
