struct object_a {
    unsigned char reserved0[0x742];
    unsigned short field_742;
};
extern "C" unsigned int function_e245c(object_a* object) {
    return object->field_742;
}
