struct object_a {
    unsigned char reserved0[0x67c];
    unsigned char field_67c;
};
extern "C" unsigned char* function_678f0(object_a* object) {
    return &object->field_67c;
}
