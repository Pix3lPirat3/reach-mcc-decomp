struct object_a {
    unsigned char field_0;
};
extern "C" bool function_7842c(object_a* object) {
    return (bool)(((unsigned char)(object->field_0 >> 5)) & 1);
}
