struct object_a {
    unsigned char reserved0[0x30];
    float field_30;
};
extern "C" float function_785e90(object_a* object) {
    return object->field_30;
}
