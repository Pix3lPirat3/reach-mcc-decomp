struct object_a {
    unsigned char reserved0[0x7fc];
    unsigned char field_7fc;
};
extern "C" unsigned char* function_e2484(object_a* object) {
    return &object->field_7fc;
}
