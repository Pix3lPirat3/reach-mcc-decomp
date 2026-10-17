struct object_a {
    unsigned char reserved0[0x50];
    unsigned long long field_50;
};
extern "C" unsigned long long function_81d5f0(object_a* object) {
    return object->field_50;
}
