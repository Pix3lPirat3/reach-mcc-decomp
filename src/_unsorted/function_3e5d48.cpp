struct object_a {
    unsigned char reserved0[0x8a];
    unsigned short field_8a;
};
extern "C" unsigned int function_3e5d48(object_a* object) {
    object->field_8a = 0;
    return 0;
}
