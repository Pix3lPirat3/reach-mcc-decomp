struct object_a {
    unsigned char reserved0[0xf83c];
    unsigned short field_f83c;
};
extern "C" unsigned int function_36cd8(object_a* object) {
    return object->field_f83c;
}
