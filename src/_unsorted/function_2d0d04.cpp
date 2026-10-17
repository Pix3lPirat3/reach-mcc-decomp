struct object_a {
    unsigned char reserved0[8];
    unsigned char field_8;
    unsigned char field_9;
};
extern "C" unsigned int function_2d0d04(object_a* object) {
    return (object->field_9 - object->field_8) + 1;
}
