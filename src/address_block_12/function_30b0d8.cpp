struct object_a {
    unsigned char reserved0[0xeb8];
    unsigned int field_eb8;
};
extern "C" unsigned int function_30b0d8(object_a* object) {
    return object->field_eb8;
}
