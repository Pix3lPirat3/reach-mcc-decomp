struct object_a {
    unsigned char reserved0[0xdc];
    float field_dc;
};
extern "C" void function_1280(object_a* object, float second) {
    object->field_dc = second;
}
