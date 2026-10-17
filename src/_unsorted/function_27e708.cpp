struct object_a {
    bool field_0;
    unsigned char reserved1[3];
    unsigned int field_4;
    unsigned int field_8;
};
extern "C" object_a* function_27e708(object_a* object) {
    object->field_4 = 0;
    object->field_8 = 0xffffffffu;
    object->field_0 = false;
    return object;
}
