struct object_a {
    unsigned char reserved0[0x140];
    unsigned int field_140;
};
extern "C" unsigned int function_2f7360(object_a* object) {
    return object->field_140;
}
