struct object_a {
    unsigned char reserved0[0x2e];
    char field_2e;
};
extern "C" unsigned int function_1c6664(object_a* object) {
    return object->field_2e;
}
