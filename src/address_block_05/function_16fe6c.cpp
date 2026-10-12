struct object_a {
    bool field_0;
    unsigned char reserved1[0xb];
    unsigned short field_c;
    unsigned char reservede[0x1e];
    unsigned short field_2c;
};
extern "C" object_a* function_16fe6c(object_a* object) {
    object->field_0 = false;
    object->field_c = 0;
    object->field_2c = 0;
    return object;
}
