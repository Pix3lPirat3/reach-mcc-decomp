struct object_a {
    unsigned char reserved0[0x1a];
    short field_1a;
};
extern "C" unsigned int function_879590(object_a* object) {
    return object->field_1a;
}
