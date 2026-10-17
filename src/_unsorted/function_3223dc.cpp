struct object_a {
    unsigned char reserved0[0x24f4];
    unsigned int field_24f4;
};
extern "C" unsigned int function_3223dc(object_a* object) {
    return object->field_24f4;
}
