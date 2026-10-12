struct object_a {
    unsigned char reserved0[0x54];
    unsigned short field_54;
    unsigned char reserved56[0x32];
    bool field_88;
};
extern "C" object_a* function_14f110(object_a* object) {
    object->field_54 = 0;
    object->field_88 = false;
    return object;
}
