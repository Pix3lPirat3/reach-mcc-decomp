struct object_a {
    unsigned char reserved0[0x64];
    bool field_64;
};
extern "C" void function_6f194c(object_a* object) {
    object->field_64 = false;
}
