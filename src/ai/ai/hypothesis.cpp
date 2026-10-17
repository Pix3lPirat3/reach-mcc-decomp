struct object_a {
    unsigned short field_0;
    unsigned char reserved2[0x1a];
    unsigned int field_1c;
    unsigned char reserved20[0xc];
    unsigned int field_2c;
};
extern "C" object_a* function_741878(object_a* object) {
    object->field_0 = 0;
    object->field_1c = 0;
    object->field_2c = 0;
    return object;
}
