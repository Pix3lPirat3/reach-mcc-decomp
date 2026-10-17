struct object_a {
    unsigned char reserved0[0x38];
    unsigned int field_38;
};
extern "C" object_a* function_3e8bd0(object_a* object) {
    object->field_38 = 0;
    return object;
}
