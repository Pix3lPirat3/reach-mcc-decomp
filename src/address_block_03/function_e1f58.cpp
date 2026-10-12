struct object_a {
    unsigned char reserved0[0xf862];
    unsigned short field_f862;
};
extern "C" unsigned int function_e1f58(object_a* object) {
    return object->field_f862;
}
