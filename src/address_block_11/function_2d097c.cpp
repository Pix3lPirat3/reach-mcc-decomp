struct object_a {
    unsigned char reserved0[0x70];
    unsigned int field_70;
};
extern "C" unsigned int function_2d097c(object_a* object) {
    return object->field_70;
}
