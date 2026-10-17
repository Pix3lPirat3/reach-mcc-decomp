struct object_a {
    unsigned char reserved0[0x15136];
    unsigned char field_15136;
};
extern "C" unsigned char* function_67efc(object_a* object) {
    return &object->field_15136;
}
