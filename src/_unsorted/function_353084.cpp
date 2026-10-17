struct object_a {
    unsigned char reserved0[0x234];
    unsigned int field_234;
};
extern "C" unsigned int function_353084(object_a* object) {
    return object->field_234;
}
