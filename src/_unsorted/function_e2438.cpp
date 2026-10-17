struct object_a {
    unsigned char reserved0[0xf860];
    unsigned char field_f860;
};
extern "C" bool function_e2438(object_a* object) {
    return (bool)(object->field_f860 & 1);
}
