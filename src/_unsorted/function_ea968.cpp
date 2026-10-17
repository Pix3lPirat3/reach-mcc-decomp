struct object_a {
    unsigned char reserved0[7];
    bool field_7;
};
extern "C" void function_ea968(object_a* object, bool second) {
    object->field_7 = second;
}
