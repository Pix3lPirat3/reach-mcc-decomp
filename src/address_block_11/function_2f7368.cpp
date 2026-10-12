struct object_a {
    unsigned char reserved0[0x130];
    unsigned long long field_130;
};
extern "C" unsigned long long function_2f7368(object_a* object) {
    return object->field_130;
}
