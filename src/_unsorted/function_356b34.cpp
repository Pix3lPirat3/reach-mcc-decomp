struct object_a {
    unsigned char reserved0[0xf0];
    unsigned int field_f0;
};
extern "C" unsigned int function_356b34(object_a* object) {
    return object->field_f0;
}
