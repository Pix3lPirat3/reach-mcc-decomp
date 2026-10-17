struct object_a {
    unsigned char reserved0[0xc0];
    unsigned int field_c0;
};
extern "C" bool function_372b40(object_a* object) {
    return object->field_c0 <= 1;
}
