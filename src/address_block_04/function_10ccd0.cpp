struct object_a {
    unsigned char reserved0[0x18];
    unsigned int field_18;
};
extern "C" object_a* function_10ccd0(object_a* object) {
    object->field_18 = 0;
    return object;
}
