struct object_a {
    unsigned char reserved0[0xf864];
    unsigned char field_f864;
};
extern "C" unsigned char* function_70e10(object_a* object) {
    return &object->field_f864;
}
