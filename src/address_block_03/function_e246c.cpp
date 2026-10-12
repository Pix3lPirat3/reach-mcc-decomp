struct object_a {
    unsigned char reserved0[0x9c4];
    unsigned short field_9c4;
};
extern "C" unsigned int function_e246c(object_a* object) {
    return object->field_9c4;
}
