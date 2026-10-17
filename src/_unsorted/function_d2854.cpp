struct object_a {
    unsigned char reserved0[0xa];
    unsigned short field_a;
};
extern "C" void function_d2854(object_a* object, unsigned short second) {
    object->field_a = second;
}
