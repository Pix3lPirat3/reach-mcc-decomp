struct object_a {
    unsigned char reserved0[0x20];
    unsigned long long field_20;
};
extern "C" unsigned long long function_79f260(object_a* object) {
    return object->field_20;
}
