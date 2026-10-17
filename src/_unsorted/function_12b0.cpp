struct object_a {
    unsigned char reserved0[0xe0];
    float field_e0;
};
extern "C" float function_12b0(object_a* object) {
    return object->field_e0;
}
