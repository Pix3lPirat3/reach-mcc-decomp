struct object_a {
    unsigned char reserved0[0x18];
    unsigned long long field_18;
};
extern "C" unsigned long long function_8cee20(object_a* object) {
    return object->field_18;
}
