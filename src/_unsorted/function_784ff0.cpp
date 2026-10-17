struct object_a {
    unsigned char reserved0[0x68];
    unsigned long long field_68;
};
extern "C" unsigned long long function_784ff0(object_a* object) {
    return object->field_68;
}
