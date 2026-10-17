struct object_a {
    unsigned char reserved0[0x280];
    unsigned int field_280;
};
extern "C" object_a* function_6b11c(object_a* object) {
    object->field_280 = 0;
    return object;
}
