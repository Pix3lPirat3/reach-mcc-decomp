struct object_a {
    unsigned char reserved0[0x60];
    unsigned long long field_60;
};
extern "C" void function_784fe0(object_a* object, unsigned long long second) {
    object->field_60 = second;
}
