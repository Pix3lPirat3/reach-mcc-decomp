struct object_a {
    unsigned char reserved0[0xf0];
    unsigned char field_f0;
};
extern "C" unsigned char* function_8b2210(object_a* object) {
    return &object->field_f0;
}
