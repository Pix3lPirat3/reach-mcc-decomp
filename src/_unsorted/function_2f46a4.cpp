struct object_a {
    unsigned char reserved0[0x810];
    unsigned int field_810;
};
extern "C" unsigned int function_2f46a4(object_a* object) {
    return object->field_810;
}
