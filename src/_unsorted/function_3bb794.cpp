struct object_a {
    unsigned char reserved0[0x3220];
    unsigned int field_3220;
};
extern "C" unsigned int function_3bb794(object_a* object) {
    return object->field_3220;
}
