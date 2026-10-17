struct object_a {
    unsigned char reserved0[0x38];
    unsigned char field_38;
};
extern "C" unsigned char* function_79eb60(object_a* object) {
    return &object->field_38;
}
