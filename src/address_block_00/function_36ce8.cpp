struct object_a {
    unsigned char reserved0[0xf83e];
    bool field_f83e;
};
extern "C" bool function_36ce8(object_a* object) {
    return object->field_f83e;
}
