struct object_a {
    unsigned char reserved0[0x9c8];
    unsigned short field_9c8;
};
extern "C" unsigned int function_e247c(object_a* object) {
    return object->field_9c8;
}
