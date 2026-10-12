struct object_a {
    unsigned char reserved0[0xe0];
    float field_e0;
};
extern "C" void function_1290(object_a* object, float second) {
    object->field_e0 = second;
}
