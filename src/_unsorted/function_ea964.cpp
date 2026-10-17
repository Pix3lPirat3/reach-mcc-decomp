struct object_a {
    unsigned char reserved0[6];
    bool field_6;
};
extern "C" void function_ea964(object_a* object, bool second) {
    object->field_6 = second;
}
