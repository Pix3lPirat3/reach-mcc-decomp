struct object_a {
    unsigned char reserved0[0x50];
    unsigned short field_50;
};
extern "C" object_a* function_321c84(object_a* object) {
    object->field_50 = 0;
    return object;
}
