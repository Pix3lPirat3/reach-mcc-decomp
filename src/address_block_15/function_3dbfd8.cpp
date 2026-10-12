struct object_a {
    unsigned char reserved0[0x40];
    bool field_40;
};
extern "C" object_a* function_3dbfd8(object_a* object) {
    object->field_40 = false;
    return object;
}
