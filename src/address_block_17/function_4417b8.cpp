struct object_a {
    unsigned char reserved0[0x14];
    unsigned int field_14;
    unsigned int field_18;
};
extern "C" unsigned int function_4417b8(object_a* object) {
    return (object->field_14 + 0x12) + object->field_18;
}
