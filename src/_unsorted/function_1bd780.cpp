struct object_a {
    unsigned char reserved0[8];
    unsigned int field_8;
};
extern "C" bool function_1bd780(object_a* object, unsigned int second) {
    return second <= (~object->field_8);
}
