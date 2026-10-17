struct object_a {
    unsigned char reserved0[4];
    bool field_4;
};
extern "C" void function_ea95c(object_a* object, bool second) {
    object->field_4 = second;
}
