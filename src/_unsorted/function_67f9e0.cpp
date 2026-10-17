struct object_a {
    unsigned char reserved0[0x40];
    bool field_40;
};
extern "C" void function_67f9e0(object_a* object, bool second) {
    object->field_40 = (bool)(second ^ 1);
}
