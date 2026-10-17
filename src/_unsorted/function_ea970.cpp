struct object_a {
    unsigned char reserved0[9];
    bool field_9;
};
extern "C" void function_ea970(object_a* object, bool second) {
    object->field_9 = second;
}
