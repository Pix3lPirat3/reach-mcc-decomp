struct object_a {
    unsigned char reserved0[0xb8];
    bool field_b8;
};
extern "C" bool function_dfe98(object_a* object) {
    return object->field_b8;
}
