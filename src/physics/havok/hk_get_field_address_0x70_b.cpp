struct object_a {
    unsigned char reserved0[0x70];
    unsigned char field_70;
};
extern "C" unsigned char* function_911030(object_a* object) {
    return &object->field_70;
}
