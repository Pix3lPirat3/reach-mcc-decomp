struct object_a {
    unsigned char reserved0[1];
    bool field_1;
};
extern "C" void function_ea954(object_a* object, bool second) {
    object->field_1 = second;
}
