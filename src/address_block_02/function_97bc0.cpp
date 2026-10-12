struct object_a {
    unsigned char reserved0[0x68];
    unsigned long long field_68;
    unsigned long long field_70;
};
extern "C" object_a* function_97bc0(object_a* object) {
    object->field_68 = 0;
    object->field_70 = 0;
    return object;
}
