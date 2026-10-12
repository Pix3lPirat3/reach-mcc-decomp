struct object_a {
    unsigned char reserved0[0x250];
    unsigned int field_250;
};
extern "C" unsigned int function_381a94(object_a* object) {
    return object->field_250;
}
