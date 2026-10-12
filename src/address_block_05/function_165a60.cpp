struct object_a {
    unsigned char reserved0[0x40];
    unsigned char field_40;
};
extern "C" unsigned char* function_165a60(object_a* object) {
    return &object->field_40;
}
