struct object_a {
    unsigned char reserved0[0x9cc];
    unsigned short field_9cc;
};
extern "C" unsigned int function_e258c(object_a* object) {
    return object->field_9cc;
}
