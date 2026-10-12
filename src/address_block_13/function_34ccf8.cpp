struct object_a {
    unsigned char reserved0[0x14c];
    unsigned int field_14c;
};
extern "C" unsigned int function_34ccf8(object_a* object, unsigned int second) {
    return object->field_14c + second;
}
