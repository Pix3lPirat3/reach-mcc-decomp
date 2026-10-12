struct object_a {
    unsigned char reserved0[8];
    bool field_8;
};
extern "C" bool function_1c3a78(object_a* object) {
    return object->field_8 == false;
}
