struct object_a {
    unsigned char reserved0[0x2fc];
    unsigned char field_2fc;
};
extern "C" unsigned char* function_678e8(object_a* object) {
    return &object->field_2fc;
}
