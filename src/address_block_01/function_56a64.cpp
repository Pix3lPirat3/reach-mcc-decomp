struct object_a {
    unsigned char reserved0[8];
    bool field_8;
};
extern "C" bool function_56a64(object_a* object) {
    return object->field_8;
}
