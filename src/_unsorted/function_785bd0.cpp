struct object_a_field_30 {
    unsigned char reserved0[8];
    float field_8;
};

struct object_a {
    unsigned char reserved0[0x30];
    object_a_field_30* field_30;
};
extern "C" float function_785bd0(object_a* object) {
    return object->field_30->field_8;
}
