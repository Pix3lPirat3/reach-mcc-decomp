struct object_a {
    unsigned char reserved0[0x28];
    unsigned char field_28;
};
extern "C" unsigned char* function_8854b0(object_a* object) {
    return &object->field_28;
}
