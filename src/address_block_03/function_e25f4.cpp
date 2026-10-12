struct object_a {
    unsigned char reserved0[0x739];
    unsigned char field_739;
};
extern "C" bool function_e25f4(object_a* object) {
    return (bool)(object->field_739 & 1);
}
