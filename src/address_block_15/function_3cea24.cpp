struct object_a {
    unsigned char reserved0[0x6e4];
    bool field_6e4;
};
extern "C" object_a* function_3cea24(object_a* object) {
    object->field_6e4 = false;
    return object;
}
