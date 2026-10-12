struct object_a {
    bool field_0;
    unsigned char reserved1[0x21];
    unsigned short field_22;
    unsigned char reserved24[4];
    unsigned short field_28;
};
extern "C" object_a* function_3dc004(object_a* object) {
    object->field_0 = false;
    object->field_22 = 0;
    object->field_28 = 0;
    return object;
}
