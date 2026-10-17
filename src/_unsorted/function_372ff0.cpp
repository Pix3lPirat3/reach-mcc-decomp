struct object_a {
    unsigned char reserved0[0xb8];
    unsigned int field_b8;
};
extern "C" unsigned int function_372ff0(object_a* object) {
    return object->field_b8;
}
