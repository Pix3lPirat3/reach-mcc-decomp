struct object_a {
    unsigned char reserved0[0x34];
    unsigned int field_34;
};
extern "C" unsigned int function_7c4a70(object_a* object) {
    return object->field_34;
}
