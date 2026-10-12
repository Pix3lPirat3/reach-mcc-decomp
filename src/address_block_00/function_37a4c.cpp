struct object_a {
    unsigned char reserved0[8];
    unsigned int field_8;
};
extern "C" object_a* function_37a4c(object_a* object) {
    object->field_8 = 0;
    return object;
}
