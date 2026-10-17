struct object_a {
    unsigned char reserved0[0xfa0];
    unsigned int field_fa0;
};
extern "C" unsigned int function_34492c(object_a* object) {
    return object->field_fa0;
}
