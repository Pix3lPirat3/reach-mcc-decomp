struct object_a {
    unsigned char reserved0[0xcba8];
    unsigned char field_cba8;
};
extern "C" unsigned char* function_6ae90(object_a* object) {
    return &object->field_cba8;
}
