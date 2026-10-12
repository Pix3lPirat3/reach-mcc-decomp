struct object_a {
    unsigned char reserved0[5];
    bool field_5;
};
extern "C" void function_ea960(object_a* object, bool second) {
    object->field_5 = second;
}
