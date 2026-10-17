struct object_a {
    unsigned char reserved0[0x170];
    unsigned char field_170;
};
extern "C" unsigned char* function_8b0ea0(object_a* object) {
    return &object->field_170;
}
