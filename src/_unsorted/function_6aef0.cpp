struct object_a {
    unsigned char reserved0[0x19ae0];
    unsigned char field_19ae0;
};
extern "C" unsigned char* function_6aef0(object_a* object) {
    return &object->field_19ae0;
}
