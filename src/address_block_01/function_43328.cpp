struct object_a {
    unsigned char reserved0[0xc];
    unsigned char field_c;
};
extern "C" unsigned char* function_43328(object_a* object) {
    return &object->field_c;
}
