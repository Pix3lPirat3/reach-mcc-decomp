struct object_a {
    unsigned char reserved0[0x188];
    unsigned char field_188;
};
extern "C" unsigned char* function_69188(object_a* object) {
    return &object->field_188;
}
