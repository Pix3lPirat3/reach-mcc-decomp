struct object_a {
    unsigned char reserved0[0x74];
    unsigned int field_74;
};
extern "C" unsigned int function_35de34(object_a* object) {
    return object->field_74;
}
