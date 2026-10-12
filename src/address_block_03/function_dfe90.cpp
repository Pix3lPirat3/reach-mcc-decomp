struct object_a {
    unsigned char reserved0[0x8c];
    unsigned char field_8c;
};
extern "C" unsigned char* function_dfe90(object_a* object) {
    return &object->field_8c;
}
