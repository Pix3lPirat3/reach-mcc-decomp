struct object_a {
    unsigned char reserved0[0x48];
    unsigned long long field_48;
};
extern "C" unsigned long long function_7cd280(object_a* object) {
    return object->field_48;
}
