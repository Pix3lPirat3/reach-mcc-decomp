struct object_a {
    unsigned char reserved0[8];
    unsigned long long field_8;
    unsigned long long field_10;
};
extern "C" object_a* function_1ba3cc(object_a* object) {
    object->field_8 = 0;
    object->field_10 = 0;
    return object;
}
