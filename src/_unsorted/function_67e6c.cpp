struct object_a {
    unsigned char reserved0[0x15036];
    unsigned char field_15036;
};
extern "C" unsigned char* function_67e6c(object_a* object) {
    return &object->field_15036;
}
