struct object_a {
    unsigned char reserved0[2];
    bool field_2;
};
extern "C" void function_ea958(object_a* object, bool second) {
    object->field_2 = second;
}
