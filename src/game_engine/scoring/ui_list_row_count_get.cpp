struct object_a {
    unsigned char reserved0[0x3794];
    unsigned int field_3794;
};
extern "C" unsigned int function_30e47c(object_a* object) {
    return object->field_3794;
}
