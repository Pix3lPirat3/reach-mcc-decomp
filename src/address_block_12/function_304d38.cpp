struct object_a {
    unsigned char reserved0[0x1208];
    unsigned int field_1208;
};
extern "C" unsigned int function_304d38(object_a* object) {
    return object->field_1208;
}
