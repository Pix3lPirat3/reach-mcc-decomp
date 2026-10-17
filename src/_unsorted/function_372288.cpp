struct object_a {
    unsigned char reserved0[0x69820];
    unsigned int field_69820;
};
extern "C" bool function_372288(object_a* object) {
    return object->field_69820 <= 1;
}
