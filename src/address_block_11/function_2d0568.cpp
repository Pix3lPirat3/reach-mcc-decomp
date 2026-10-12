struct object_a {
    unsigned char reserved0[0xa];
    bool field_a;
};
extern "C" bool function_2d0568(object_a* object) {
    return object->field_a;
}
