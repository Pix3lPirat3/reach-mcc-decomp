struct object_a {
    unsigned char reserved0[0x20];
    unsigned char field_20;
};
extern "C" unsigned char* function_8ddec0(object_a* object) {
    return &object->field_20;
}
