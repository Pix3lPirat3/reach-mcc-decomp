struct object_a {
    unsigned char reserved0[0x58];
    unsigned char field_58;
};
extern "C" unsigned char* function_e244c(object_a* object) {
    return &object->field_58;
}
