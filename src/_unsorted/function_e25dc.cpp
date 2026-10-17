struct object_a {
    unsigned char reserved0[0x738];
    unsigned char field_738;
};
extern "C" bool function_e25dc(object_a* object) {
    return (bool)(((unsigned char)(object->field_738 >> 3)) & 1);
}
