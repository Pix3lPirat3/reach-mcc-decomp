struct object_a {
    unsigned char reserved0[0x34];
    unsigned int field_34;
};
extern "C" unsigned int function_44016c(object_a* object) {
    return object->field_34 + 2;
}
