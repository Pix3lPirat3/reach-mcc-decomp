struct object_a {
    unsigned char reserved0[4];
    unsigned int field_4;
};
extern "C" bool function_121dd4(object_a* object, unsigned int second) {
    return object->field_4 != second;
}
