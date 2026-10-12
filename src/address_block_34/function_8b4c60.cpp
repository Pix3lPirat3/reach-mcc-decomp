struct object_a {
    unsigned char reserved0[0x54];
    float field_54;
};
extern "C" float function_8b4c60(object_a* object) {
    return object->field_54;
}
