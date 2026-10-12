struct object_a {
    unsigned char reserved0[0x54];
    float field_54;
};
extern "C" void function_8b4c70(object_a* object, float second) {
    object->field_54 = second;
}
