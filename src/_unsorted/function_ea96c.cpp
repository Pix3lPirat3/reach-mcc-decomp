struct object_a {
    unsigned char reserved0[8];
    bool field_8;
};
extern "C" void function_ea96c(object_a* object, bool second) {
    object->field_8 = second;
}
