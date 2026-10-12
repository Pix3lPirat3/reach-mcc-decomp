struct object_a {
    unsigned char reserved0[0xf2];
    short field_f2;
};
extern "C" unsigned int function_37b5a8(object_a* object) {
    return object->field_f2;
}
