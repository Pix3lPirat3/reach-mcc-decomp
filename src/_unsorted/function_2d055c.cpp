struct object_a {
    unsigned char reserved0[8];
    unsigned int field_8;
    unsigned int field_c;
};
extern "C" unsigned int function_2d055c(object_a* object) {
    return (object->field_c - object->field_8) + 1;
}
