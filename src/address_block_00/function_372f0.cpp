struct object_a {
    unsigned char reserved0[4];
    bool field_4;
    unsigned char reserved5[0xe];
    bool field_13;
    unsigned char reserved14[0xe];
    bool field_22;
};
extern "C" object_a* function_372f0(object_a* object) {
    object->field_4 = false;
    object->field_13 = false;
    object->field_22 = false;
    return object;
}
