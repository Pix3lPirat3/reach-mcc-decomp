struct object_a {
    unsigned char reserved0[0x2d];
    bool field_2d;
};
extern "C" void function_1de5f0(object_a* object, bool second) {
    object->field_2d = second;
}
