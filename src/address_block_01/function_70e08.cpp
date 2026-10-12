struct object_a {
    unsigned char reserved0[0xf861];
    char field_f861;
};
extern "C" unsigned int function_70e08(object_a* object) {
    return object->field_f861;
}
