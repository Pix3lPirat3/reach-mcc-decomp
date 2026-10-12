struct object_a {
    unsigned char reserved0[0x2b8];
    unsigned char field_2b8;
};
extern "C" unsigned char* function_37b2c(object_a* object) {
    return &object->field_2b8;
}
