struct object_a {
    unsigned char reserved0[8];
    bool field_8;
};
extern "C" object_a* function_421be0(object_a* object) {
    object->field_8 = false;
    return object;
}
