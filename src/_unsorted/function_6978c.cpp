struct object_a {
    unsigned char reserved0[0x90c];
    unsigned char field_90c;
};
extern "C" unsigned char* function_6978c(object_a* object) {
    return &object->field_90c;
}
