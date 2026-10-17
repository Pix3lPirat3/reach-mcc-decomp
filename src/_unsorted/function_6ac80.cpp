struct object_a {
    unsigned char reserved0[0x28];
    unsigned char field_28;
};
extern "C" unsigned char* function_6ac80(object_a* object) {
    return &object->field_28;
}
