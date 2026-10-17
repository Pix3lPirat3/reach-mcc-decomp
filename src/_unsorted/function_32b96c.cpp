struct object_a {
    unsigned char reserved0[0x112a08];
    unsigned int field_112a08;
};
extern "C" unsigned int function_32b96c(object_a* object) {
    return object->field_112a08;
}
