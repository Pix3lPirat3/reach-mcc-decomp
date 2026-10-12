struct object_a {
    unsigned char reserved0[0x24a18];
    unsigned int field_24a18;
    unsigned char reserved24a1c[8];
    unsigned int field_24a24;
};
extern "C" void function_238dfc(object_a* object) {
    object->field_24a24 = 0;
    object->field_24a18 = 0;
}
