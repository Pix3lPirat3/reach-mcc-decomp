struct object_a {
    unsigned char reserved0[0x7e4];
    unsigned short field_7e4;
};
extern "C" unsigned int function_e259c(object_a* object) {
    return object->field_7e4;
}
