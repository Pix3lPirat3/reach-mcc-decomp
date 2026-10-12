struct object_a {
    unsigned char reserved0[0x18];
    unsigned int field_18;
    unsigned int field_1c;
};
extern "C" void function_27c250(object_a* object, unsigned int second, unsigned int third) {
    object->field_18 = second >> 2;
    object->field_1c = third >> 2;
}
