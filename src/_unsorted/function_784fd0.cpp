struct object_a {
    unsigned char reserved0[0x60];
    unsigned long long field_60;
};
extern "C" unsigned long long function_784fd0(object_a* object) {
    return object->field_60;
}
