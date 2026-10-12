struct object_a {
    unsigned char reserved0[0x10];
    unsigned int field_10;
};
extern "C" unsigned int function_79f290(object_a* object, unsigned int second) {
    return object->field_10 & second;
}
