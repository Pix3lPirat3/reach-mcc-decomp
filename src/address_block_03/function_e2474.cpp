struct object_a {
    unsigned char reserved0[0x9c6];
    unsigned short field_9c6;
};
extern "C" unsigned int function_e2474(object_a* object) {
    return object->field_9c6;
}
