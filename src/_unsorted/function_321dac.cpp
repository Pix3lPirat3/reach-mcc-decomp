struct object_a {
    unsigned char reserved0[0x4af4];
    unsigned int field_4af4;
};
extern "C" unsigned int function_321dac(object_a* object) {
    return object->field_4af4;
}
