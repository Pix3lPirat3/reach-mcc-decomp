struct object_a {
    unsigned char reserved0[4];
    unsigned char field_4;
};
extern "C" unsigned char* function_368e0(object_a* object) {
    return &object->field_4;
}
