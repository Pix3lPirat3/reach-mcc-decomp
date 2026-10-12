struct object_a {
    unsigned char reserved0[0x118];
    float field_118;
};
extern "C" void function_8b3c60(object_a* object, float second) {
    object->field_118 = second;
}
