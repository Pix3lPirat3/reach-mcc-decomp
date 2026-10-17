struct object_a {
    unsigned char reserved0[0x280];
    unsigned long long field_280;
};
extern "C" unsigned long long function_311f60(object_a* object) {
    return object->field_280;
}
