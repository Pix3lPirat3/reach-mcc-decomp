struct object_a {
    unsigned char reserved0[0x430];
    unsigned int field_430;
};
extern "C" unsigned int function_34894c(object_a* object) {
    return object->field_430;
}
