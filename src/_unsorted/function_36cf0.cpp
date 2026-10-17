struct object_a {
    unsigned char reserved0[0xe30c];
    unsigned int field_e30c;
};
extern "C" unsigned int function_36cf0(object_a* object) {
    return object->field_e30c;
}
