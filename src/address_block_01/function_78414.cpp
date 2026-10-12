struct object_a {
    unsigned char field_0;
};
extern "C" bool function_78414(object_a* object) {
    return (bool)(((unsigned char)(object->field_0 >> 2)) & 1);
}
