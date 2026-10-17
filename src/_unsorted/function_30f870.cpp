struct object_a {
    unsigned char reserved0[0x2fc0];
    unsigned int field_2fc0;
};
extern "C" unsigned int function_30f870(object_a* object) {
    return object->field_2fc0;
}
