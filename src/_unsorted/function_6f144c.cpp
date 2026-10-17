struct object_a {
    unsigned char reserved0[0xc4];
    bool field_c4;
};
extern "C" void function_6f144c(object_a* object) {
    object->field_c4 = false;
}
