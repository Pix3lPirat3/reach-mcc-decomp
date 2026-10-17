struct object_a {
    unsigned char reserved0[0x54];
    unsigned int field_54;
};
extern "C" unsigned int function_63be70(object_a* object, unsigned int second) {
    object->field_54 = second;
    return 0;
}
