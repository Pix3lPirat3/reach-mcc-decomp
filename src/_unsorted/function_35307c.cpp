struct object_a {
    unsigned char reserved0[0x230];
    unsigned int field_230;
};
extern "C" unsigned int function_35307c(object_a* object) {
    return object->field_230;
}
