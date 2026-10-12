struct object_a {
    unsigned char reserved0[0x18];
    unsigned int field_18;
    unsigned char reserved1c[6];
    unsigned short field_22;
};
extern "C" unsigned int function_1c3b0c(object_a* object) {
    return object->field_18 - object->field_22;
}
