struct object_a {
    unsigned char reserved0[0x60];
    unsigned char field_60;
};
extern "C" unsigned char* function_dfe88(object_a* object) {
    return &object->field_60;
}
