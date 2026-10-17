struct object_a {
    unsigned char reserved0[0x18];
    unsigned char field_18;
};
extern "C" unsigned char* function_6ae60(object_a* object) {
    return &object->field_18;
}
