struct object_a {
    unsigned char reserved0[0x9ca];
    unsigned short field_9ca;
};
extern "C" unsigned int function_e2464(object_a* object) {
    return object->field_9ca;
}
