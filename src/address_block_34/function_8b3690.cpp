struct object_a {
    unsigned char reserved0[0xf0];
    unsigned long long field_f0;
};
extern "C" unsigned long long function_8b3690(object_a* object) {
    return object->field_f0;
}
