struct object_a {
    bool field_0;
    unsigned char reserved1[0x7f];
    unsigned short field_80;
};
extern "C" object_a* function_a4644(object_a* object) {
    object->field_0 = false;
    object->field_80 = 0;
    return object;
}
