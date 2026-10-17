struct object_a {
    unsigned char reserved0[0x28];
    unsigned long long field_28;
    unsigned long long field_30;
};
extern "C" object_a* function_8f698(object_a* object) {
    object->field_28 = 0;
    object->field_30 = 0;
    return object;
}
