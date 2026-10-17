struct object_a {
    unsigned char reserved0[0xa0];
    bool field_a0;
};
extern "C" void function_6f1944(object_a* object) {
    object->field_a0 = false;
}
