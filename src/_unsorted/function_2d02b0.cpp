struct object_a {
    unsigned char reserved0[0x2c];
    unsigned int field_2c;
};
extern "C" unsigned int function_2d02b0(object_a* object) {
    return object->field_2c;
}
