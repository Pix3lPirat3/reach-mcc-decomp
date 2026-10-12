struct object_a {
    unsigned char reserved0[0x2733];
    bool field_2733;
};
extern "C" void function_87f6c0(object_a* object, bool second) {
    object->field_2733 = second;
}
