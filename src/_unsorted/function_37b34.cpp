struct object_a {
    unsigned char reserved0[0x2f8];
    unsigned char field_2f8;
};
extern "C" unsigned char* function_37b34(object_a* object) {
    return &object->field_2f8;
}
