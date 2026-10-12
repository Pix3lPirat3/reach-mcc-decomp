struct object_a {
    unsigned char reserved0[0x2c];
    unsigned char field_2c;
};
extern "C" unsigned char* function_e2444(object_a* object) {
    return &object->field_2c;
}
