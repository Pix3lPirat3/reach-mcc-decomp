struct object_a_field_10 {
    unsigned char reserved0[0x38];
    unsigned int field_38;
};

struct object_a {
    unsigned char reserved0[0x10];
    object_a_field_10* field_10;
};
extern "C" unsigned int hk_load_dword_field_0x38_of_child_8eb1b0(object_a* object) {
    return object->field_10->field_38;
}
