struct object_a {
    unsigned char reserved0[0x740];
    bool field_740;
};
extern "C" bool function_678f8(object_a* object) {
    return object->field_740;
}
