struct object_a {
    unsigned char reserved0[0xad0];
    unsigned short field_ad0;
};
extern "C" unsigned int function_694e8(object_a* object) {
    return object->field_ad0;
}
