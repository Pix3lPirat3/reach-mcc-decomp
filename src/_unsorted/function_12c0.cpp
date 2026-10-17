struct object_a {
    unsigned char reserved0[4];
    float field_4;
};
extern "C" void function_12c0(object_a* object, float second) {
    object->field_4 = second;
}
