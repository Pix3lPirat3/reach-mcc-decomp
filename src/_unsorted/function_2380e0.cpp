struct object_a {
    unsigned char reserved0[8];
    unsigned char field_8;
};
extern "C" unsigned char* function_2380e0(object_a* object) {
    return &object->field_8;
}
