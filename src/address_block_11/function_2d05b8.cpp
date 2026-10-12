struct object_a {
    unsigned char reserved0[8];
    char field_8;
    char field_9;
};
extern "C" unsigned int function_2d05b8(object_a* object) {
    return (object->field_9 - object->field_8) + 1;
}
