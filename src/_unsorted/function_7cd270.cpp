struct object_a {
    unsigned char reserved0[0x30];
    unsigned long long field_30;
};
extern "C" unsigned long long function_7cd270(object_a* object) {
    return object->field_30;
}
