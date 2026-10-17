struct object_a {
    unsigned char reserved0[2];
    unsigned short field_2;
};
extern "C" unsigned int function_cc614(object_a* object) {
    return object->field_2 << 2;
}
