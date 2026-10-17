struct object_a {
    unsigned char reserved0[0x2c4];
    unsigned char field_2c4;
};
extern "C" bool function_67f74(object_a* object) {
    return (bool)(object->field_2c4 & 1);
}
