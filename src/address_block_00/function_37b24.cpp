struct object_a {
    unsigned char reserved0[2];
    short field_2;
};
extern "C" unsigned int function_37b24(object_a* object) {
    return object->field_2;
}
