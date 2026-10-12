struct object_a {
    unsigned char reserved0[0x8c];
    unsigned int field_8c;
};
extern "C" unsigned int function_3759e0(object_a* object) {
    return object->field_8c;
}
