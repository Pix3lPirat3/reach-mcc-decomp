struct object_a {
    unsigned char reserved0[0xb9];
    bool field_b9;
};
extern "C" bool function_dfea0(object_a* object) {
    return object->field_b9;
}
