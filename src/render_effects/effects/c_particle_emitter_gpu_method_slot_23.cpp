struct object_a {
    unsigned char reserved0[0x18];
    unsigned int field_18;
};
extern "C" unsigned int function_27c190(object_a* object) {
    return object->field_18 << 3;
}
