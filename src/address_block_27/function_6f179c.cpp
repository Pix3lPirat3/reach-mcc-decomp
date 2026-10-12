struct object_a {
    unsigned char reserved0[0xa4];
    bool field_a4;
};
extern "C" void function_6f179c(object_a* object) {
    object->field_a4 = false;
}
