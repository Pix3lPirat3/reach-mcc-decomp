struct object_a {
    unsigned char reserved0[0x74];
    unsigned int field_74;
};
extern "C" object_a* function_22e4a4(object_a* object) {
    object->field_74 = 0;
    return object;
}
