struct object_a {
    unsigned char reserved0[0x744];
    unsigned short field_744;
};
extern "C" unsigned int function_e2594(object_a* object) {
    return object->field_744;
}
