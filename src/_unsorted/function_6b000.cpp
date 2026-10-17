struct object_a {
    unsigned char reserved0[0xa28];
    unsigned char field_a28;
};
extern "C" unsigned char* function_6b000(object_a* object) {
    return &object->field_a28;
}
