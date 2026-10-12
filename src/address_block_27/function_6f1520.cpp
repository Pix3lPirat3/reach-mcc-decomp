struct object_a {
    unsigned char reserved0[0x58];
    bool field_58;
};
extern "C" void function_6f1520(object_a* object) {
    object->field_58 = false;
}
