struct object_a_field_20 {
    unsigned char reserved0[0x10];
    float field_10;
};

struct object_a {
    unsigned char reserved0[0x20];
    object_a_field_20* field_20;
};
extern "C" float function_912c00(object_a* object) {
    return object->field_20->field_10;
}
