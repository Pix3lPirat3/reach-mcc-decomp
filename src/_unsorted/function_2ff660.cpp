struct object_a {
    unsigned char reserved0[0x13120];
    unsigned int field_13120;
};
extern "C" unsigned int function_2ff660(object_a* object) {
    return object->field_13120;
}
