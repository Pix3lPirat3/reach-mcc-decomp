struct object_a {
    unsigned char reserved0[0x28];
    unsigned long long field_28;
};
extern "C" void function_347fdc(object_a* object) {
    if (object->field_28 != 0) {
        object->field_28 = 0;
    }
}
