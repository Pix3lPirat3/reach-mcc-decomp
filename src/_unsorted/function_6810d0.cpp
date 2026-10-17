struct object_a {
    unsigned char reserved0[0x18];
    unsigned short field_18;
};
extern "C" object_a* function_6810d0(object_a* object) {
    object->field_18 = 0;
    return object;
}
