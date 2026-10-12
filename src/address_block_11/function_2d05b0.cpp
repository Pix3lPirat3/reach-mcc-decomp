struct object_a {
    unsigned char reserved0[8];
    unsigned char field_8;
};
extern "C" unsigned char function_2d05b0(object_a* object, unsigned char second) {
    return (unsigned char)(object->field_8 + second);
}
