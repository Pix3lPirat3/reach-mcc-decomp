struct object_a {
    unsigned char reserved0[8];
    unsigned int field_8;
};
extern "C" bool function_67f50(object_a* object) {
    return object->field_8 == 1;
}
