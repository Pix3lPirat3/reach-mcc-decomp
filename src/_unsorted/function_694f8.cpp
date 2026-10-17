struct object_a {
    unsigned char reserved0[0xc8];
    unsigned char field_c8;
};
extern "C" unsigned char* function_694f8(object_a* object) {
    return &object->field_c8;
}
