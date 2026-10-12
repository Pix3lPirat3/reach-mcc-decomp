struct object_a {
    unsigned char reserved0[0xc];
    bool field_c;
};
extern "C" object_a* function_171088(object_a* object) {
    object->field_c = false;
    return object;
}
