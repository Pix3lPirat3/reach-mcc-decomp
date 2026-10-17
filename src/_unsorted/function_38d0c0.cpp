struct object_a {
    unsigned char reserved0[8];
    unsigned long long field_8;
    unsigned long long field_10;
};
extern "C" bool function_38d0c0(object_a* object) {
    object->field_8 = 0;
    object->field_10 = 0;
    return false;
}
