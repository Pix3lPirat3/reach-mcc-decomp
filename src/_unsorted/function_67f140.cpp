struct object_a {
    unsigned char reserved0[0x50];
    unsigned char field_50;
};
extern "C" unsigned char* function_67f140(object_a* object) {
    return &object->field_50;
}
