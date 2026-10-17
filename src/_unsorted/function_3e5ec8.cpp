struct object_a {
    unsigned char reserved0[0x88];
    unsigned short field_88;
};
extern "C" unsigned int function_3e5ec8(object_a* object) {
    object->field_88 = 0;
    return 0;
}
