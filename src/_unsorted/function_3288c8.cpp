struct object_a {
    unsigned char reserved0[0x374];
    unsigned int field_374;
};
extern "C" unsigned int function_3288c8(object_a* object) {
    return object->field_374;
}
