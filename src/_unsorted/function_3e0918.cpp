struct object_a {
    unsigned char reserved0[0x708];
    unsigned long long field_708;
};
extern "C" unsigned long long function_3e0918(object_a* object) {
    return object->field_708;
}
