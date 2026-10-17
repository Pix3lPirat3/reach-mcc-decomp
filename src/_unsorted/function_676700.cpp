struct object_a {
    unsigned char reserved0[0x18];
    unsigned int field_18;
};
extern "C" unsigned int function_676700(object_a* object, unsigned int second) {
    object->field_18 += second;
    return second;
}
