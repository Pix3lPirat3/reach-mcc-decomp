struct object_a {
    unsigned char reserved0[8];
    unsigned int field_8;
    unsigned int field_c;
};
extern "C" object_a* function_45136c(object_a* object) {
    object->field_8 = 0xffffffffu;
    object->field_c = 0xffffffffu;
    return object;
}
