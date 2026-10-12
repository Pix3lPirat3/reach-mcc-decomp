struct object_a {
    unsigned char reserved0[0xdc];
    float field_dc;
};
extern "C" float function_12a0(object_a* object) {
    return object->field_dc;
}
