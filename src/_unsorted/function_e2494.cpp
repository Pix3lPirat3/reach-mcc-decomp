struct object_a {
    unsigned char reserved0[0x854];
    unsigned char field_854;
};
extern "C" unsigned char* function_e2494(object_a* object) {
    return &object->field_854;
}
