struct object_a {
    unsigned char reserved0[0x1c8];
    unsigned char field_1c8;
};
extern "C" unsigned char* function_69500(object_a* object) {
    return &object->field_1c8;
}
