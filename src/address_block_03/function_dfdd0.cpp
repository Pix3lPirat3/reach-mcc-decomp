struct object_a {
    unsigned char reserved0[4];
    bool field_4;
};
extern "C" bool function_dfdd0(object_a* object) {
    return object->field_4;
}
