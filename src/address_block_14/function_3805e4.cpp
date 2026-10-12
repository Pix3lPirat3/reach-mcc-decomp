struct object_a {
    unsigned char reserved0[0xcd78];
    unsigned int field_cd78;
};
extern "C" unsigned int function_3805e4(object_a* object) {
    return object->field_cd78;
}
