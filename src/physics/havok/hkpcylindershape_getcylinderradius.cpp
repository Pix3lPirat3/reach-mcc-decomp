struct object_a {
    unsigned char reserved0[0x28];
    float field_28;
};
extern "C" float function_8879d0(object_a* object) {
    return object->field_28;
}
