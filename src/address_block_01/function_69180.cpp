struct object_a {
    unsigned char reserved0[0x88];
    unsigned char field_88;
};
extern "C" unsigned char* function_69180(object_a* object) {
    return &object->field_88;
}
