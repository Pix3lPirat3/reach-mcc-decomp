struct object_a {
    unsigned char reserved0[0x6b50];
    unsigned int field_6b50;
};
extern "C" unsigned int function_3783bc(object_a* object) {
    return object->field_6b50;
}
