struct object_a {
    unsigned char reserved0[0x4220];
    unsigned int field_4220;
};
extern "C" unsigned int function_33d88c(object_a* object) {
    return object->field_4220;
}
