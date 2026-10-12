struct object_a {
    unsigned char reserved0[0x7ea0];
    unsigned int field_7ea0;
};
extern "C" unsigned int function_37a5e0(object_a* object) {
    return object->field_7ea0;
}
