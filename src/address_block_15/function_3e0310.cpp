struct object_a {
    unsigned char reserved0[0xb10];
    unsigned long long field_b10;
};
extern "C" bool function_3e0310(object_a* object) {
    object->field_b10 = 0;
    return true;
}
