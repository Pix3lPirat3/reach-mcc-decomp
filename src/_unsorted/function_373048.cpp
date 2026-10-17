struct object_a {
    unsigned char reserved0[0xa8];
    unsigned int field_a8;
};
extern "C" bool function_373048(object_a* object) {
    return object->field_a8 <= 1;
}
