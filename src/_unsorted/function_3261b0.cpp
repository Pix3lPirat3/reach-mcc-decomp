struct object_a {
    unsigned char reserved0[0x98];
    unsigned int field_98;
};
extern "C" unsigned int function_3261b0(object_a* object) {
    return object->field_98;
}
