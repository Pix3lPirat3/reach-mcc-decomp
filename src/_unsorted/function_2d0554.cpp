struct object_a {
    unsigned char reserved0[8];
    unsigned int field_8;
};
extern "C" unsigned int function_2d0554(object_a* object, unsigned int second) {
    return object->field_8 + second;
}
