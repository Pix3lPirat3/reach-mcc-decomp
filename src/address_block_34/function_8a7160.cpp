struct object_a {
    unsigned char reserved0[0x78];
    void * field_78;
};
extern "C" void * function_8a7160(object_a* object) {
    return object->field_78;
}
