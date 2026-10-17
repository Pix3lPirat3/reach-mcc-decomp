struct object_a {
    unsigned char reserved0[0x14f36];
    unsigned char field_14f36;
};
extern "C" unsigned char* function_67e64(object_a* object) {
    return &object->field_14f36;
}
