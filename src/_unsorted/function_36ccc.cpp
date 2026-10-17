struct object_a {
    unsigned char reserved0[0xf838];
    unsigned char field_f838;
};
extern "C" bool function_36ccc(object_a* object) {
    return (bool)(object->field_f838 & 1);
}
