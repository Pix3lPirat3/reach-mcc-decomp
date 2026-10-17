struct object_a {
    unsigned char reserved0[0x91c];
    unsigned char field_91c;
};
extern "C" unsigned char* function_69794(object_a* object) {
    return &object->field_91c;
}
