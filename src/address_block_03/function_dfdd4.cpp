struct object_a {
    unsigned char reserved0[5];
    bool field_5;
};
extern "C" bool function_dfdd4(object_a* object) {
    return object->field_5;
}
