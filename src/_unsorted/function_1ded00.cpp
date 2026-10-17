struct object_a {
    unsigned char reserved0[0x2c];
    float field_2c;
};
extern "C" void function_1ded00(object_a* object, float second) {
    object->field_2c = second;
}
