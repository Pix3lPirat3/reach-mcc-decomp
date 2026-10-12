struct object_a {
    unsigned char reserved0[0xb4];
    bool field_b4;
};
extern "C" void function_67fb10(object_a* object, bool second) {
    object->field_b4 = second;
}
