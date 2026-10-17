struct object_a {
    unsigned char reserved0[7];
    bool field_7;
};
extern "C" bool function_dfddc(object_a* object) {
    return object->field_7;
}
