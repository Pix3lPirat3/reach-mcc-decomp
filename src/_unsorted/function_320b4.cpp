struct object_a {
    unsigned char reserved0[0x10];
    unsigned int field_10;
    unsigned char reserved14[0xc];
    unsigned int field_20;
};
extern "C" bool function_320b4(object_a* object, unsigned int second) {
    return second <= (object->field_10 - object->field_20);
}
