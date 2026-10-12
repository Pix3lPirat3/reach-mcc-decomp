struct object_a {
    unsigned char reserved0[0x78];
    unsigned int field_78;
};
extern "C" unsigned int function_318370(object_a* object) {
    return object->field_78;
}
