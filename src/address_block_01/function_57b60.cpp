struct object_a {
    bool field_0;
    unsigned char reserved1[0x6f];
    bool field_70;
};
extern "C" object_a* function_57b60(object_a* object) {
    object->field_0 = false;
    object->field_70 = false;
    return object;
}
