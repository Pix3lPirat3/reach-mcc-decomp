struct object_a {
    unsigned char reserved0[8];
    unsigned short field_8;
};
extern "C" object_a* function_373e2c(object_a* object) {
    object->field_8 = 0;
    return object;
}
