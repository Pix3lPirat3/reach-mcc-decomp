struct object_a {
    unsigned char reserved0[3];
    unsigned char field_3;
};
extern "C" bool function_43310(object_a* object) {
    return ((unsigned char)(object->field_3 - 1)) <= 0xc;
}
