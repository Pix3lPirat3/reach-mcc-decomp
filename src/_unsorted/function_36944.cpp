struct object_a {
    unsigned char reserved0[0x2c0];
    unsigned char field_2c0;
};
extern "C" unsigned char* function_36944(object_a* object) {
    return &object->field_2c0;
}
