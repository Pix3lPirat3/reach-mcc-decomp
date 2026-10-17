struct object_a {
    unsigned char reserved0[0x978];
    unsigned int field_978;
};
extern "C" unsigned int function_2ff038(object_a* object) {
    return object->field_978;
}
