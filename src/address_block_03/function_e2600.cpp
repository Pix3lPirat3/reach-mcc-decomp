struct object_a {
    unsigned char reserved0[0x98c];
    unsigned char field_98c;
};
extern "C" unsigned char* function_e2600(object_a* object) {
    return &object->field_98c;
}
