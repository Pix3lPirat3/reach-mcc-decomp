struct object_a {
    unsigned char reserved0[0xc];
    unsigned int field_c;
};
extern "C" unsigned int function_2cc620(object_a* object) {
    return object->field_c;
}
