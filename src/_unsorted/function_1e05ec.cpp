struct object_a {
    unsigned char reserved0[0x18];
    bool field_18;
};
extern "C" bool function_1e05ec(object_a* object) {
    return object->field_18;
}
