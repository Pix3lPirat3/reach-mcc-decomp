struct object_a {
    unsigned char reserved0[0x40];
    bool field_40;
};
extern "C" bool function_67f9d0(object_a* object) {
    return object->field_40 == false;
}
