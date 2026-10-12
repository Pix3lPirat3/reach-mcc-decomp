struct object_a {
    unsigned char reserved0[0xf8];
    unsigned long long field_f8;
};
extern "C" unsigned long long function_8b36b0(object_a* object) {
    return object->field_f8;
}
