struct object_a {
    unsigned char reserved0[0x3c];
    unsigned int field_3c;
};
extern "C" object_a* function_3e8bc8(object_a* object) {
    object->field_3c = 0;
    return object;
}
