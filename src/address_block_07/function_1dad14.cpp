struct object_a {
    unsigned char reserved0[0x198];
    bool field_198;
};
extern "C" bool function_1dad14(object_a* object) {
    return object->field_198;
}
