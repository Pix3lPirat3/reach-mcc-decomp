struct object_a {
    unsigned char reserved0[0x10];
    unsigned char field_10;
};
extern "C" unsigned char* function_6af80(object_a* object) {
    return &object->field_10;
}
