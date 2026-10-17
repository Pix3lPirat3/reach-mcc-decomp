struct object_a {
    unsigned char reserved0[0x20];
    unsigned int field_20;
};
extern "C" object_a* function_67878(object_a* object) {
    object->field_20 = 0;
    return object;
}
