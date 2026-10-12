struct object_a {
    unsigned char reserved0[0x60];
    bool field_60;
};
extern "C" void function_6f16f4(object_a* object) {
    object->field_60 = false;
}
