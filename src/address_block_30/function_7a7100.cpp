struct object_a {
    unsigned char reserved0[0x28];
    unsigned long long field_28;
};
extern "C" unsigned long long function_7a7100(object_a* object) {
    return object->field_28;
}
