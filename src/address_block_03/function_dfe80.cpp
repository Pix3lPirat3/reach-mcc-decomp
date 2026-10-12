struct object_a {
    unsigned char reserved0[0x34];
    unsigned char field_34;
};
extern "C" unsigned char* function_dfe80(object_a* object) {
    return &object->field_34;
}
