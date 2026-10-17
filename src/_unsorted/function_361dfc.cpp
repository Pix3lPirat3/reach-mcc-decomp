struct object_a {
    unsigned char reserved0[0x80];
    unsigned int field_80;
};
extern "C" unsigned int function_361dfc(object_a* object) {
    return object->field_80;
}
