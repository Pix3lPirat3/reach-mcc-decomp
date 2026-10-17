struct object_a {
    unsigned char reserved0[0x60];
    unsigned long long field_60;
    unsigned long long field_68;
    unsigned long long field_70;
};
extern "C" unsigned int function_59cb40(object_a* object, unsigned long long second, unsigned long long third, unsigned long long fourth) {
    object->field_60 = second;
    object->field_68 = third;
    object->field_70 = fourth;
    return 0;
}
