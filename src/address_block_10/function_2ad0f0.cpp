struct object_a {
    unsigned char reserved0[0x10];
    unsigned long long field_10;
};
extern "C" object_a* function_2ad0f0(object_a* object) {
    object->field_10 = 0;
    return object;
}
