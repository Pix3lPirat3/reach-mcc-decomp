struct object_a {
    unsigned char reserved0[0x70];
    unsigned long long field_70;
};
extern "C" unsigned long long function_784fc0(object_a* object) {
    return object->field_70 & 0xfffffffffffffffeull;
}
