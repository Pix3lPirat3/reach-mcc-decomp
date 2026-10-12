struct object_a {
    unsigned char reserved0[0x828];
    unsigned char field_828;
};
extern "C" unsigned char* function_e248c(object_a* object) {
    return &object->field_828;
}
