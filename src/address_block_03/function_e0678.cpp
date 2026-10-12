struct object_a {
    unsigned char reserved0[3];
    bool field_3;
};
extern "C" void function_e0678(object_a* object, bool second) {
    object->field_3 = second;
}
