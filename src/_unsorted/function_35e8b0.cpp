struct object_a {
    unsigned char reserved0[0xa78];
    unsigned int field_a78;
};
extern "C" unsigned int function_35e8b0(object_a* object) {
    return object->field_a78;
}
