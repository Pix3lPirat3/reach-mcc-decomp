struct object_a {
    unsigned char reserved0[0x71];
    bool field_71;
    unsigned char reserved72[0x26];
    bool field_98;
};
extern "C" bool function_369454(object_a* object) {
    object->field_98 = object->field_71;
    return object->field_71;
}
