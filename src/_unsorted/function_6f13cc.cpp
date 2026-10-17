struct object_a {
    unsigned char reserved0[0x14];
    bool field_14;
};
extern "C" void function_6f13cc(object_a* object) {
    object->field_14 = false;
}
