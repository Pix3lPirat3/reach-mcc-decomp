struct object_a {
    unsigned char reserved0[0x5678];
    unsigned int field_5678;
};
extern "C" unsigned int function_3454c0(object_a* object) {
    return object->field_5678;
}
