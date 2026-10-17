struct object_a {
    unsigned char reserved0[0xc];
    bool field_c;
};
extern "C" void function_6f1350(object_a* object) {
    object->field_c = false;
}
