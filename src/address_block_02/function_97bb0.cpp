struct object_a {
    unsigned char reserved0[0xa];
    bool field_a;
};
extern "C" void function_97bb0(object_a* object) {
    object->field_a = true;
}
