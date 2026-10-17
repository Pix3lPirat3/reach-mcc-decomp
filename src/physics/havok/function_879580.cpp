struct object_a {
    unsigned char reserved0[8];
    unsigned long long field_8;
};
extern "C" unsigned long long function_879580(object_a* object) {
    return object->field_8;
}
