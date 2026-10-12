struct object_a {
    unsigned char reserved0[0xf83c];
    unsigned short field_f83c;
};
extern "C" void function_36ce0(object_a* object, unsigned short second) {
    object->field_f83c = second;
}
