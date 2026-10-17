struct object_a {
    unsigned short field_0;
    unsigned char reserved2[0x1fe];
    unsigned short field_200;
};
extern "C" object_a* function_355ed0(object_a* object) {
    object->field_0 = 0;
    object->field_200 = 0;
    return object;
}
