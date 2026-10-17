struct object_a {
    unsigned char reserved0[0x28];
    unsigned short field_28;
};
extern "C" object_a* function_6810e0(object_a* object) {
    object->field_28 = 0;
    return object;
}
