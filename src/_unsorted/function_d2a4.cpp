struct object_a {
    unsigned char reserved0[4];
    bool field_4;
};
extern "C" object_a* function_d2a4(object_a* object) {
    object->field_4 = false;
    return object;
}
