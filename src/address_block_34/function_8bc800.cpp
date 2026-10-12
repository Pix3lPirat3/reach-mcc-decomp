struct object_a {
    unsigned char reserved0[0x78];
    unsigned char field_78;
};
extern "C" unsigned char* function_8bc800(object_a* object) {
    return &object->field_78;
}
