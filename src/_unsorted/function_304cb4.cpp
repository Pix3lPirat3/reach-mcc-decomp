struct object_a {
    unsigned char reserved0[0x9b4];
    unsigned int field_9b4;
};
extern "C" unsigned int function_304cb4(object_a* object) {
    return object->field_9b4;
}
